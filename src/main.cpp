/* Copyright 2023 nacky823
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "myname_pubsub/main.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace myname_pubsub
{

Myname::Myname(const rclcpp::NodeOptions & options)
: Node("myname_pubsub", options)
  , count_(0)
  , ms_(0)
{
  /* declare parameter */
  this->declare_parameter("pub_name", "hajime");
  std::chrono::duration<double, std::milli> initial_value(2.0);
  this->declare_parameter("pub_rate", initial_value.count());

  /* get parameter pub_name */
  name_ = this->get_parameter("pub_name").as_string();

  /* get parameter pub_rate */
  auto second = this->get_parameter("pub_rate").as_double();
  std::chrono::milliseconds mil_second(static_cast<int>(second * 1000));
  ms_ = mil_second;

  publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
  timer_ = this->create_wall_timer(
    ms_, std::bind(&Myname::timer_callback, this)
  );

  RCLCPP_INFO(this->get_logger(), "Initial name is %s.", name_.c_str());
  RCLCPP_INFO(this->get_logger(), "Initial period is %lf[s].", second);

  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "name_topic", 10, std::bind(&Myname::topic_callback, this, _1)
  );
}

void myname_pubsub::Myname::timer_callback()
{
  /* declare message */
  auto message = std_msgs::msg::String();

  /* get parameter pub_rate */
  auto second = this->get_parameter("pub_rate").as_double();
  std::chrono::milliseconds mil_second(static_cast<int>(second * 1000));
  static std::chrono::milliseconds pre_mil_second = mil_second;

  /* get parameter pub_name */
  std::string name = this->get_parameter("pub_name").as_string();
  static std::string pre_name = name;

  /* change name process */
  if (pre_name != name) {
    RCLCPP_INFO(this->get_logger(), "Change name to %s.", name.c_str());

    name_ = name;
  }
  pre_name = name;

  /* messabe process */
  if (count_ != 9) {
    message.data = name_ + ", count = " + std::to_string(count_++);
  } else {
    message.data = "Mr.Ikebe, count = " + std::to_string(count_);
    count_ = 0;
  }

  /* change period process */
  if (pre_mil_second != mil_second) {
    RCLCPP_INFO(this->get_logger(), "Changed period to %lf[s].", second);

    ms_ = mil_second;

    timer_ = this->create_wall_timer(ms_, std::bind(&Myname::timer_callback, this));
  }
  pre_mil_second = mil_second;

  //RCLCPP_INFO(this->get_logger(), "Now period is %lf[s].", second);

  /* set parameter */
  rclcpp::Parameter sec_param("pub_rate", second);
  std::vector<rclcpp::Parameter> sec_parameters{sec_param};
  this->set_parameters(sec_parameters);

  publisher_->publish(message);
}

void Myname::topic_callback(const std_msgs::msg::String & msg) const
{
  RCLCPP_INFO(this->get_logger(), "Subscibed : '%s'", msg.data.c_str());
}

} // namespace myname_pubsub

int main(int argc, char * argv[])
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto myname = std::make_shared<myname_pubsub::Myname>(options);
  exec.add_node(myname);

  exec.spin();

  rclcpp::shutdown();

  return 0;
}
