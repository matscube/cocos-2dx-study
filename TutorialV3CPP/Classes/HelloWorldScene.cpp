#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    mySprite = Sprite::create("CloseNormal.png");
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite);

//    auto action = MoveBy::create(1, Point(50, 150));
//    mySprite->runAction(action);
    
//    auto action2 = MoveTo::create(1, Point(50, 150));
//    mySprite->runAction(action2);
    
//    auto action3 = JumpBy::create(1, Point(100, 0),150, 1);
//    mySprite->runAction(action3);
    
//    auto action4 = JumpTo::create(1, Point(100, 100), 150, 1);
//    mySprite->runAction(action4);
    
//    ccBezierConfig bezier;
//    bezier.controlPoint_1 = Point(0, visibleSize.height / 2);
//    bezier.controlPoint_2 = Point(300, -visibleSize.height / 2);
//    bezier.endPosition = Point(200, 100);
    
//    auto action5 = BezierBy::create(3, bezier);
//    mySprite->runAction(action5);
    
    auto action = Place::create(Point(98, 280));
    mySprite->runAction(action);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
