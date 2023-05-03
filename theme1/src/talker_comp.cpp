#include "theme1/talker_comp.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std::chrono_literals;

namespace theme1
{

theme1::TalkerComp::TalkerComp() : Node("talker_comp")
                         , count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("name_topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&TalkerComp::timer_callback, this)
    );
}

void theme1::TalkerComp::timer_callback()
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
    RCLCPP_INFO(this->get_logger(), "Publishing : '%s'", message.data.c_str());

    publisher_->publish(message); // publish
}

} // namespace theme1

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(theme1::TalkerComp)

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<theme1::TalkerComp>());
    rclcpp::shutdown();
    return 0;
}