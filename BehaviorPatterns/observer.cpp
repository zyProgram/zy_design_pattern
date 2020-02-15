//
// Created by mars on 2020/2/15.
//

#include <iostream>
#include <string>
#include <list>
#include <bits/unique_ptr.h>

class observer{
public:
    virtual void update() = 0;
    virtual void show() = 0;
    virtual void set(int num) = 0;
};

class notifyList;
class clientObserver:public observer{
private:
    int index;
    notifyList *nList;
public:
    void setList(notifyList *_nList){
        nList = _nList;
    }
    void update(){
        std::cout<<"myset change from "<<index<<" to "<< --index<<std::endl;
    }
    void leave();
    void set(int id){
        index = id;
    }
    void show(){
        std::cout<<"index:"<<index<<std::endl;
    }
};

class notifyList{
private:
    std::list<observer*> listInstance;
    void leave(int index)
    {
        if(index <= listInstance.size()){
            int i = 1;
            observer* reObs;
            for(auto iter:listInstance){
                if(i == index){
                    reObs = iter;
                }
                if(i>index){
                    iter->update();
                }
                i++;
            }
            listInstance.remove(reObs);
        }
    }
public:
    friend void clientObserver::leave();
    void show(){
        std::cout<<"queue info:"<<std::endl;
        for(auto iter:listInstance) {
            iter->show();
        }
    }
    void addObserver(observer *obs){
        listInstance.push_back(obs);
        obs->set(listInstance.size());
    }

};

void clientObserver::leave(){
    nList->leave(index);
}


class clientFactory{
public:
    static std::list<std::unique_ptr<observer>> productList;
public:
    static observer * produce(std::string info) {
        if (info == "client") {
            auto *p = new clientObserver;
            productList.push_back(std::unique_ptr<observer>(p));
            return p;
        }
    }

};
std::list<std::unique_ptr<observer>> clientFactory::productList;

int main(){
    auto listPtr=std::unique_ptr<notifyList>(new notifyList);
    auto *list = listPtr.get();
    clientObserver *p = dynamic_cast<clientObserver*>(clientFactory::produce("client"));
    list->addObserver(p);
    p->setList(list);
    for (int i =0 ;i<10;i++){
        auto *p = dynamic_cast<clientObserver*>(clientFactory::produce("client"));
        p->setList(list);
        list->addObserver(p);
    }
    list->show();
    p->leave();
    list->show();
}

