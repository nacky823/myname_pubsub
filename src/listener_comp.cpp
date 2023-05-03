#include "theme1/listener_comp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <memory>

using std::placeholders::_1;

namespace theme1
{

ListenerComp::ListenerComp(const rclcpp::NodeOptions &options)
: Node("listener_comp", options)
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "name_topic", 10, std::bind(&ListenerComp::topic_callback, this, _1)
    );
}

ListenerComp::ListenerComp() : Node("listener_comp")
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "name_topic", 10, std::bind(&ListenerComp::topic_callback, this, _1)
    );
}

void ListenerComp::topic_callback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "Subscibed : '%s'", msg.data.c_str());
}

} // namespace theme1

RCLCPP_COMPONENTS_REGISTER_NODE(theme1::ListenerComp)

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<theme1::ListenerComp>());
    rclcpp::shutdown();
    return 0;
}