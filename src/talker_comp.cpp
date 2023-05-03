#include "myname_pubsub/talker_comp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std::chrono_literals;

namespace myname_pubsub
{

TalkerComp::TalkerComp(const rclcpp::NodeOptions & options)
: Node("talker_comp", options)
, count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&TalkerComp::timer_callback, this)
    );
}

TalkerComp::TalkerComp()
: Node("talker_comp")
, count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&TalkerComp::timer_callback, this)
    );
}

void myname_pubsub::TalkerComp::timer_callback()
{
    auto message = std_msgs::msg::String(); // declare message

    /* messabe data */
    if(count_ != 9)
    {
        message.data = "nacky, count = " + std::to_string(count_++);
    }
    else
    {
        message.data = "Mr.Ikebe, count = " + std::to_string(count_);
        count_ = 0;
    }

    /* publish message */
    //RCLCPP_INFO(this->get_logger(), "Publishing : '%s'", message.data.c_str());

    publisher_->publish(message); // publish
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