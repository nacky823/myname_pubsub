#ifndef TALKER_COMP_HPP_
#define TALKER_COMP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace myname_pubsub
{

class TalkerComp : public rclcpp::Node
{
public:
    explicit TalkerComp(const rclcpp::NodeOptions & options);

private:
    size_t count_;
    std::chrono::milliseconds ms_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void timer_callback();
};
    
} // namespace myname_pubsub

#endif // TALKER_COMP_HPP_