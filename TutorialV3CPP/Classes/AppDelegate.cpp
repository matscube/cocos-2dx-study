#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto fileUtils = FileUtils::getInstance();
    auto screenSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;
    
    if ( 2048 == screenSize.width || 2048 == screenSize.height ) {
        resDirOrders.push_back("ipadhd");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(2048, 1536, ResolutionPolicy::NO_BORDER);
        
    } else if ( 1024 == screenSize.width || 1024 == screenSize.height ) {
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(1024, 768, ResolutionPolicy::NO_BORDER);
        
    } else if ( 1136 == screenSize.width || 1136 == screenSize.height ) {
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::NO_BORDER);
        
    } else if ( 960 == screenSize.width || 960 == screenSize.height ) {
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(960, 640, ResolutionPolicy::NO_BORDER);
    } else {
        resDirOrders.push_back("iphone");
        
        glview->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);
    }
    
    fileUtils->setSearchPaths(resDirOrders);
    
    
    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
