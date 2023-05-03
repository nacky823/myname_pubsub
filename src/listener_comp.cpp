#include "myname_pubsub/listener_comp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <memory>

using std::placeholders::_1;

namespace myname_pubsub
{

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

RCLCPP_COMPONENTS_REGISTER_NODE(myname_pubsub::ListenerComp)

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions options;
    rclcpp::spin(std::make_shared<myname_pubsub::ListenerComp>(options));
    rclcpp::shutdown();
    return 0;
}