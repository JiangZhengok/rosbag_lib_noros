#include <iostream>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/String.h>

int main(int argc, char **argv) {
  rosbag::Bag bag;
  // bag.open("/home/yqnj/2_data/data/rosbags/0717/P-6.0-27-20240717_170347_080-20240717_170758_192.bag", rosbag::bagmode::Read);
  bag.open("/opt/data/parking_map_data/hpa_data/P-6.0-27-20240717_170347_080-20240717_170758_192.bag", rosbag::bagmode::Read);

  rosbag::View view(bag);

  for (const auto &m : view) {
    std::cout << m.getTime() << ", " << m.getTopic() << ", " << m.getDataType()
              << std::endl;

    if (m.getDataType() == "std_msgs/String") 
    {
      std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
      if (s != nullptr) 
      {
        std::cout << s->data << std::endl;
      }
    }
  }

  bag.close();

  return 0;
}