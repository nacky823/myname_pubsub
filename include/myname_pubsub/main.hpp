#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace myname_pubsub
{

class TalkerComp : public rclcpp::Node
{
public:
    TalkerComp();
    explicit TalkerComp(const rclcpp::NodeOptions & options);

private:
    size_t count_;
    std::chrono::milliseconds ms_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void timer_callback();
};

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

#endif // MAIN_HPP_