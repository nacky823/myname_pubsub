#ifndef LISTENER_COMP_HPP_
#define LISTENER_COMP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace theme1
{

class ListenerComp : public rclcpp::Node
{
public:
    explicit ListenerComp(const rclcpp::NodeOptions &options);
    ListenerComp();

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void topic_callback(const std_msgs::msg::String &msg) const;

};

} // namespace theme1

#endif // LISTENER_COMP_HPP_