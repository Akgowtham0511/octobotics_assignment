#include <cstdlib>
#include "adra/adra_api_base.h"
#include "adra_ros/AdraMsg.h"
#include "ros/ros.h"
#include "adra_ros/Api.h"

AdraApiBase *adra = NULL;
void getting_pose_calback(const adra_ros::AdraMsg::ConstPtr& msg) {
  ROS_INFO("id: %d position: %f velocity: %f current: %f", msg->id, msg->position, msg->velocity, msg->current);
  cout<<"The intial position is: %position"<<endl;
//  proividing a final pose at this variable
  float position = 10 // random value for the postion
  adra->set_pos_target(msg->id,position);
  // the final of the adra(arm) we are setting to a random value
  int final_pos = adra->get_pos_current;

  while(final_pos != position)
  {
      cout<<"The target set has reached";
      adra->set_pos_target(msg->id,position);

      if(final_pos == (position+1) || final_pos == (position-1))
      {
          cout<<"The final pose has reached";
          break;
      }
  }
}

int main(int argc, char **argv) {
ros::init(argc, argv, "setting final pose");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("adra_publish", 1000, getting_pose_calback);
  ros::spin();
  return 0;

}