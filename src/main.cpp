#include "myname_pubsub/main.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <chrono>
#include <functional>
#include <string>

using std::placeholders::_1;
using namespace std::chrono_literals;

namespace myname_pubsub
{

TalkerComp::TalkerComp(const rclcpp::NodeOptions & options)
: Node("talker_comp", options)
, count_(0)
, ms_(0)
{
    /* declare parameter */
    std::chrono::duration<double, std::milli> initial_value(2.0);
    this->declare_parameter("pub_rate", initial_value.count());

    publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
    timer_ = this->create_wall_timer(
        2000ms, std::bind(&TalkerComp::timer_callback, this)
    );

    RCLCPP_INFO(this->get_logger(), "Initial period is %lf[s].", initial_value.count());
}

void myname_pubsub::TalkerComp::timer_callback()
{
    /* declare message */
    auto message = std_msgs::msg::String();

    /* messabe process */
    if(count_ != 9)
    {
        message.data = "nacky, count = " + std::to_string(count_++);
    }
    else
    {
        message.data = "Mr.Ikebe, count = " + std::to_string(count_);
        count_ = 0;
    }

    /* get parameter */
    auto second = this->get_parameter("pub_rate").as_double();
    std::chrono::milliseconds mil_second(static_cast<int>(second * 1000));

    static std::chrono::milliseconds pre_mil_second = mil_second;

    /* change period process */
    if(pre_mil_second != mil_second)
    {
        RCLCPP_INFO(this->get_logger(), "Changed period to %lf[s].", second);

        ms_ = mil_second;

        timer_ = this->create_wall_timer(ms_, std::bind(&TalkerComp::timer_callback, this));
    }
    pre_mil_second = mil_second;

    //RCLCPP_INFO(this->get_logger(), "Now period is %lf[s].", second);

    /* set parameter */
    rclcpp::Parameter sec_param("pub_rate", second);
    std::vector<rclcpp::Parameter> sec_parameters{sec_param};
    this->set_parameters(sec_parameters);

    publisher_->publish(message);
}

ListenerComp::ListenerComp(const rclcpp::NodeOptions &options)
: Node("listener_comp", options)
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "name_topic", 10, std::bind(&ListenerComp::topic_callback, this, _1)
    );
}

void ListenerComp::topic_callback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "Subscibed : '%s'", msg.data.c_str());
}

} // namespace myname_pubsub

int main(int argc, char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor exec;
    rclcpp::NodeOptions options;

    auto talker = std::make_shared<myname_pubsub::TalkerComp>(options);
    exec.add_node(talker);
    auto listener = std::make_shared<myname_pubsub::ListenerComp>(options);
    exec.add_node(listener);

    exec.spin();

    rclcpp::shutdown();

    return 0;
}