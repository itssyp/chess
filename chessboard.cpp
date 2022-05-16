#include "chessboard.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "iostream"
using namespace genv;

chessboard::chessboard(yWindow *w,std::string name,int x, int y, int sx, int sy):Widget(w,name,x,y,sx,sy){
    for (int j=0; j<8; j++){
        for (int i=0; i<8; i++){
            piece *p;
            p = nullptr;
            if (j==1) p = new pawn(false,i,j);
            if (j==6) p = new pawn(true,i,j);
            if ((j==0&&i==0) || (j==0&&i==7)) p = new rook(false,i,j);
            if ((j==7&&i==0) || (j==7&&i==7)) p = new rook(true,i,j);
            if ((j==0&&i==1) || (j==0&&i==6)) p = new bishop(false,i,j);
            if ((j==7&&i==1) || (j==7&&i==6)) p = new bishop(true,i,j);
            bool b=false;
            if ((j+i)%2==1) b= true;
            tile tmp =tile(i*100,j*100,100,100,b,p,[i,j,this](tile &t){
//                        std::cout<<j<<','<< i <<std::endl;
                        if (this->get_selectedPiece()==nullptr && t.getPiece()!=nullptr){
//                            std::cout << "occupied" << std::endl;
                            this->set_selectedPiece(t.getPiece());
//                            t.getPiece()->getPos();
                            t.setPiece(nullptr,this->getTiles());
                        }
                        else if (this->get_selectedPiece()!=nullptr){
//                            this->get_selectedPiece()->_move(t.);
                            if (t.setPiece(this->get_selectedPiece(),this->getTiles())){
                                this->set_selectedPiece(0);
                            }
                        }

                        });
            tiles[j][i] = tmp;
        }
    }
}

void chessboard::draw(){
    for (int j=0; j<8; j++){
        for (int i=0; i<8; i++){
            tiles[j][i].draw();
        }
    }
}

void chessboard::handle(genv::event ev){
    for (int j=0; j<8; j++){
        for (int i=0; i<8; i++){
            if (ev.pos_x<(i+1)*100 && ev.pos_x>i*100 && ev.pos_y<(j+1)*100 && ev.pos_y>j*100)
                tiles[j][i].handle(ev);
        }
    }
}

void chessboard::set_selectedPiece(piece *p){
    _selectedPiece=p;
}

piece *chessboard::get_selectedPiece(){
    return _selectedPiece;
}

std::vector<std::vector<tile>> chessboard::getTiles(){
    std::vector<std::vector<tile>> v;
    for (int j=0; j<8; j++){
        std::vector<tile> tmp;
        for (int i=0; i<8; i++){
        tmp.push_back(tiles[j][i]);
        }
        v.push_back(tmp);
    }
    return v;
}

std::vector<std::string> chessboard::getVal(){}
