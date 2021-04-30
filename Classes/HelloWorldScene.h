#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "bidmad/RewardInterface.h"
#include "bidmad/InterstitialInterface.h"
#include "bidmad/CommonInterface.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    RewardInterface* ri;
    InterstitialInterface* ii;
    
    void initInterstitial();
    void loadInterstitial();
    void showInterstitial();
    
    void initReward();
    void loadReward();
    void showReward();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
