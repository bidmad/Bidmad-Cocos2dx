#ifndef __INTERSTITIALSAMPLE_SCENE_H__
#define __INTERSTITIALSAMPLE_SCENE_H__

#include "cocos2d.h"
#include "bidmad/InterstitialInterface.h"

class InterstitialSampleScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    InterstitialInterface* ii;

    void initInterstitial();
    void loadInterstitial();
    void showInterstitial();

    void backScene();
    // implement the "static create()" method manually
    CREATE_FUNC(InterstitialSampleScene);
};

#endif // __INTERSTITIALSAMPLE_SCENE_H__
