#ifndef TALKER_COMP_HPP_
#define TALKER_COMP_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace theme1
{

class TalkerComp : public rclcpp::Node
{
public:
    TalkerComp();

private:
    size_t count_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    void timer_callback();
};
    
} // namespace theme1

#endif // TALKER_COMP_HPP_