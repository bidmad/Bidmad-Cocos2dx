#ifndef __REWARDSAMPLE_SCENE_H__
#define __REWARDSAMPLE_SCENE_H__

#include "cocos2d.h"
#include "bidmad/RewardInterface.h"

class RewardSampleScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    RewardInterface* ri;
    
    void initReward();
    void loadReward();
    void showReward();

    void backScene();
    // implement the "static create()" method manually
    CREATE_FUNC(RewardSampleScene);
};

#endif // __REWARDSAMPLE_SCENE_H__
