#include "myname_pubsub/talker_comp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std::chrono_literals;

namespace myname_pubsub
{

TalkerComp::TalkerComp() : Node("talker_comp") {}

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

    RCLCPP_INFO(this->get_logger(), "Now period is %lf[s].", second);

    /* set parameter */
    rclcpp::Parameter sec_param("pub_rate", second);
    std::vector<rclcpp::Parameter> sec_parameters{sec_param};
    this->set_parameters(sec_parameters);

    publisher_->publish(message);
}

} // namespace myname_pubsub

RCLCPP_COMPONENTS_REGISTER_NODE(myname_pubsub::TalkerComp)

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<myname_pubsub::TalkerComp>());
    rclcpp::shutdown();
    return 0;
}