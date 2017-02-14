#include "TextInput.h"

//Scene* TextInput::createScene()
//{
//    auto scene = Scene::create();
//    auto layer = TextInput::create();
//    scene->addChild(layer);
//    return scene;
//}


bool TextInput::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//得到屏幕相关大小
    visibleSize = Director::getInstance()->getVisibleSize();  

    //创建文本框  
    //第一个参数：文本框中显示的内容  
    //第二个参数：字体  
    //第三个参数：文本的大小 

	// 创建文本框1
    textEdit = CCTextFieldTTF::textFieldWithPlaceHolder("Please input:","Arial", 36);  
    textEdit->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));  
	textEdit->setColorSpaceHolder(Color3B::BLUE);
    this->addChild(textEdit);  
/*  
	// 创建文本框（2）
	textEdit2 = CCTextFieldTTF::textFieldWithPlaceHolder("Please input:",CCSizeMake(100,100), CCTextAlignment::LEFT, "Arial", 36);
	textEdit2->setPosition(Vec2(visibleSize.width/2,visibleSize.height/4));
	this->addChild(textEdit2);
*/


	// 文字按钮——密码 模式
	auto btn_psw = MenuItemFont::create("password",CC_CALLBACK_1(TextInput::menupswCallback,this));  
	btn_psw->setPosition(Vec2(btn_psw->getContentSize().width,visibleSize.height/4)); 
	
	// 文字按钮——展示 文本框内容
	auto btn_show = MenuItemFont::create("show",CC_CALLBACK_1(TextInput::menushowCallback,this));
	btn_show->setPosition(Vec2(btn_psw->getContentSize().width*2,visibleSize.height/4));

	// 文字按钮——计算文本框内字符个数
	auto btn_count = MenuItemFont::create("count",CC_CALLBACK_1(TextInput::menucountCallback,this));
	btn_count->setPosition(Vec2(btn_psw->getContentSize().width,visibleSize.height/6));

	// 文字按钮——改变文本框内字体颜色
	auto btn_color = MenuItemFont::create("color",CC_CALLBACK_1(TextInput::menuchangeColorCallback,this));
	btn_color->setPosition(Vec2(btn_psw->getContentSize().width*2,visibleSize.height/6));

	auto menu = Menu::create(btn_psw,btn_show,btn_count,btn_color, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	auto label_show = Label::create(textEdit->getString(),"Arial", 24);
	label_show->setPosition(Vec2(visibleSize.width/2-50,visibleSize.height/1.5));
	label_show->setTag(111);
	this->addChild(label_show);

	auto label_count = Label::create(textEdit->getString(),"Arial", 24);
	label_count->setPosition(Vec2(visibleSize.width/2+50,visibleSize.height/1.5));
	label_count->setTag(112);
	this->addChild(label_count);


    //当触摸到控件的时候弹出软键盘  
    setTouchMode(kCCTouchesOneByOne);  
    setTouchEnabled(true);  

    return true;
}

// 触摸事件
bool TextInput::onTouchBegan(CCTouch* touch, CCEvent* ev)  
{  
    //用于判断是否点中了控件  
    bool isClicked = textEdit->boundingBox().containsPoint(touch->getLocation());  

    //如果点中了控件  
	if( isClicked )  
    {  
        //弹出软键盘  
        textEdit->attachWithIME();  
    }
	else
	{
		textEdit->detachWithIME();
	}

    //表示接受触摸消息  
    return true;  
} 

// 是否设置成 密码 模式
void TextInput::menupswCallback(cocos2d::Ref* pSender)
{
	if( textEdit->isSecureTextEntry() )
	{
		textEdit->setSecureTextEntry(false);
	}
	else
	{
		textEdit->setSecureTextEntry(true);
	}
}

// 展示文本框内容
void TextInput::menushowCallback(cocos2d::Ref* pSender)
{
	auto label = (Label*) this->getChildByTag(111);
	label->setString(textEdit->getString());
}

// 计算文本框内容字符个数
void TextInput::menucountCallback(cocos2d::Ref* pSender)
{
	auto label = (Label*) this->getChildByTag(112);
	label->setString( StringUtils::format(" %d ",textEdit->getCharCount()) );
}

// 改变文本框字体颜色
void TextInput::menuchangeColorCallback(cocos2d::Ref* pSender)
{
	textEdit->setColor(Color3B::GREEN);
}