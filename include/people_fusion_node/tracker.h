#ifndef PEOPLEFUSIONNODE_INCLUDE_PEOPLE_FUSION_NODE_TRACKER_H_
#define PEOPLEFUSIONNODE_INCLUDE_PEOPLE_FUSION_NODE_TRACKER_H_

// Ros includes
#include <ros/ros.h>

// Own includes
#include <people_fusion_node/state_pos_vel.h>
#include <people_fusion_node/detection/detection.h>


class Tracker{

	private:
    unsigned int id_;

		ros::Time initiationTime_;
		StatePosVel initialState_;

		ros::Time currentTime_;
		StatePosVel currentState_;

		// For easy outstreaming
		friend std::ostream& operator<<(std::ostream&, const Tracker&);




	public:
		Tracker(StatePosVel init, ros::Time initialTime);

		unsigned int getId() const { return this->id_; };

		ros::Time getCurrentTime() { return this->currentTime_; };

		StatePosVel getCurrentState() { return this->currentState_; };

		void predict(ros::Time updateTime);

		void update(DetectionPtr detection);

		StatePosVel getCurrentState() const { return this->currentState_; };

};

// Define the Share pointer
typedef boost::shared_ptr<Tracker> TrackerPtr;




#endif /* PEOPLEFUSIONNODE_INCLUDE_PEOPLE_FUSION_NODE_TRACKER_H_ */
