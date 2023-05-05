#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace myname_pubsub
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

class TalkerComp : public rclcpp::Node
{
public:
    explicit TalkerComp(const rclcpp::NodeOptions & options);
    TalkerComp();

private:
    size_t count_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void timer_callback();
};

} // namespace myname_pubsub

#endif // MAIN_HPP_