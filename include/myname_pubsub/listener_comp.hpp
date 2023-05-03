#ifndef LISTENER_COMP_HPP_
#define LISTENER_COMP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace myname_pubsub
{

class ListenerComp : public rclcpp::Node
{
public:
    ListenerComp();
    explicit ListenerComp(const rclcpp::NodeOptions &options);

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void topic_callback(const std_msgs::msg::String &msg) const;

};

} // namespace myname_pubsub

#endif // LISTENER_COMP_HPP_