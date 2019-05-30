#include "bsp_ebox.h"
#include "gui_button.h"
#include "gui_sidebar.h"

#include "ui_main.h"
#include "ebox_mem.h"
#include "ui.h"
#include "ui_setValue.h"
//static GuiButton  btnTest(10,10,60,40);
//static GuiSideBar bar(1,10,100,5);
static GuiButton *btn1;
static GuiButton *btn2;
static GuiSideBar *bar;
static GuiSideBar *bar1;

MainPage *pageMain = new MainPage("main");

static void onBtn1Click()
{
    ui.open(pageSetValue);
    UART.println("UI BTN CLICK");
}

MainPage::MainPage(String name):GuiPage(name){

};

MainPage::~MainPage()
{

    for(int i = 0; i < activityList.size(); i++)
    {
        delete (GuiBase *)activityList.data(i);
    }
    for(int i = 0; i < baseList.size(); i++)
    {
        delete (GuiBase *)activityList.data(i);
    }
}
void MainPage::create()
{

    _gpu->clear();
    btn1 = new GuiButton(10,10,60,40);
    btn2 = new GuiButton(10,60,60,40);
    bar = new GuiSideBar(1,10,100,5);
    bar1 = new GuiSideBar(1,100,100,5);
    
    btn1->click = onBtn1Click;
    regedit(btn1);
    regedit(btn2);
    regedit(bar);
    regedit(bar1);
    selection = 0;
    GuiPage::create();
}

void MainPage::loop()
{
    
}
void MainPage::event(Object *sender,GuiMessage *msg)
{
    UART.println(sender->name);
    UART.println(msg->str);
    
    if(msg->str == "d")
    {
        if(get_selected_object()->click != NULL)
            get_selected_object()->click();
    }
        
    if(msg->str == "w")
    {
        if(selection > 0)
        {
                UART.printf("select:--\r\n");
            selection--;
            update_select();
        }
    }
    
        
    if(msg->str == "s")
    {
        if(selection < activityList.size() - 1)
        {
            UART.printf("select:++\r\n");
            UART.flush();
               selection++;
                update_select();
        }
    }
    UART.printf("select:%d/%d\r\n",selection,activityList.size());

    
}