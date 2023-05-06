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

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace myname_pubsub
{

class Myname : public rclcpp::Node
{
public:
  explicit Myname(const rclcpp::NodeOptions & options);

private:
  size_t count_;
  std::string name_;
  std::chrono::milliseconds ms_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  void timer_callback();
  void topic_callback(const std_msgs::msg::String & msg) const;

};

} // namespace myname_pubsub

#endif // MAIN_HPP_
