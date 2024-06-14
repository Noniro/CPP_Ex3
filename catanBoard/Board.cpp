#include "Board.hpp"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Enums.hpp"

using namespace std;

Board::Board() {
    initialize();
}

void Board::initialize() {
    vector<shared_ptr<Tile>> allTiles = { //defalut tiles setup
        make_shared<WoodTile>(5), make_shared<RockTile>(9) , make_shared<WoodTile>(3),
        make_shared<WheatTile>(11),make_shared<SheepTile>(8) , make_shared<BrickTile>(5), make_shared<WheatTile>(6),
         make_shared<SheepTile>(4), make_shared<RockTile>(11), make_shared<DesertTile>() ,make_shared<WoodTile>(2) , make_shared<SheepTile>(10),
        make_shared<BrickTile>(3), make_shared<WheatTile>(8), make_shared<BrickTile>(4),make_shared<WheatTile>(12),
        make_shared<SheepTile>(9),make_shared<WoodTile>(6), make_shared<RockTile>(10),
         
    };


    tiles = allTiles;

    shared_ptr<Vertex> v0 = make_shared<Vertex>();
    shared_ptr<Vertex> v1 = make_shared<Vertex>();
    shared_ptr<Vertex> v2 = make_shared<Vertex>();
    shared_ptr<Vertex> v3 = make_shared<Vertex>();
    shared_ptr<Vertex> v4 = make_shared<Vertex>();
    shared_ptr<Vertex> v5 = make_shared<Vertex>();
    shared_ptr<Vertex> v6 = make_shared<Vertex>();
    shared_ptr<Vertex> v7 = make_shared<Vertex>();
    shared_ptr<Vertex> v8 = make_shared<Vertex>();
    shared_ptr<Vertex> v9 = make_shared<Vertex>();
    shared_ptr<Vertex> v10 = make_shared<Vertex>();
    shared_ptr<Vertex> v11 = make_shared<Vertex>();
    shared_ptr<Vertex> v12 = make_shared<Vertex>();
    shared_ptr<Vertex> v13 = make_shared<Vertex>();
    shared_ptr<Vertex> v14 = make_shared<Vertex>();
    shared_ptr<Vertex> v15 = make_shared<Vertex>();
    shared_ptr<Vertex> v16 = make_shared<Vertex>();
    shared_ptr<Vertex> v17 = make_shared<Vertex>();
    shared_ptr<Vertex> v18 = make_shared<Vertex>();
    shared_ptr<Vertex> v19 = make_shared<Vertex>();
    shared_ptr<Vertex> v20 = make_shared<Vertex>();
    shared_ptr<Vertex> v21 = make_shared<Vertex>();
    shared_ptr<Vertex> v22 = make_shared<Vertex>();
    shared_ptr<Vertex> v23 = make_shared<Vertex>();
    shared_ptr<Vertex> v24 = make_shared<Vertex>();
    shared_ptr<Vertex> v25 = make_shared<Vertex>();
    shared_ptr<Vertex> v26 = make_shared<Vertex>();
    shared_ptr<Vertex> v27 = make_shared<Vertex>();
    shared_ptr<Vertex> v28 = make_shared<Vertex>();
    shared_ptr<Vertex> v29 = make_shared<Vertex>();
    shared_ptr<Vertex> v30 = make_shared<Vertex>();
    shared_ptr<Vertex> v31 = make_shared<Vertex>();
    shared_ptr<Vertex> v32 = make_shared<Vertex>();
    shared_ptr<Vertex> v33 = make_shared<Vertex>();
    shared_ptr<Vertex> v34 = make_shared<Vertex>();
    shared_ptr<Vertex> v35 = make_shared<Vertex>();
    shared_ptr<Vertex> v36 = make_shared<Vertex>();
    shared_ptr<Vertex> v37 = make_shared<Vertex>();
    shared_ptr<Vertex> v38 = make_shared<Vertex>();
    shared_ptr<Vertex> v39 = make_shared<Vertex>();
    shared_ptr<Vertex> v40 = make_shared<Vertex>();
    shared_ptr<Vertex> v41 = make_shared<Vertex>();
    shared_ptr<Vertex> v42 = make_shared<Vertex>();
    shared_ptr<Vertex> v43 = make_shared<Vertex>();
    shared_ptr<Vertex> v44 = make_shared<Vertex>();
    shared_ptr<Vertex> v45 = make_shared<Vertex>();
    shared_ptr<Vertex> v46 = make_shared<Vertex>();
    shared_ptr<Vertex> v47 = make_shared<Vertex>();
    shared_ptr<Vertex> v48 = make_shared<Vertex>();
    shared_ptr<Vertex> v49 = make_shared<Vertex>();
    shared_ptr<Vertex> v50 = make_shared<Vertex>();
    shared_ptr<Vertex> v51 = make_shared<Vertex>();
    shared_ptr<Vertex> v52 = make_shared<Vertex>();
    shared_ptr<Vertex> v53 = make_shared<Vertex>();

    vertices = {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,
                v11, v12, v13, v14, v15, v16, v17, v18, v19, v20,
                v21, v22, v23, v24, v25, v26, v27, v28, v29, v30,
                v31, v32, v33, v34, v35, v36, v37, v38, v39, v40,
                v41, v42, v43, v44, v45, v46, v47, v48, v49, v50,
                v51, v52, v53};

    //72 edges
shared_ptr<Edge> e0 = make_shared<Edge>(v3, v0);
shared_ptr<Edge> e1 = make_shared<Edge>(v0, v4);
shared_ptr<Edge> e2 = make_shared<Edge>(v4, v1);
shared_ptr<Edge> e3 = make_shared<Edge>(v1, v5);
shared_ptr<Edge> e4 = make_shared<Edge>(v5, v2);
shared_ptr<Edge> e5 = make_shared<Edge>(v2, v6);
shared_ptr<Edge> e6 = make_shared<Edge>(v3, v7);
shared_ptr<Edge> e7 = make_shared<Edge>(v4, v8);
shared_ptr<Edge> e8 = make_shared<Edge>(v5, v9);
shared_ptr<Edge> e9 = make_shared<Edge>(v6, v10);
shared_ptr<Edge> e10 = make_shared<Edge>(v11, v7);
shared_ptr<Edge> e11 = make_shared<Edge>(v7, v12);
shared_ptr<Edge> e12 = make_shared<Edge>(v12, v8);
shared_ptr<Edge> e13 = make_shared<Edge>(v8, v13);
shared_ptr<Edge> e14 = make_shared<Edge>(v13, v9);
shared_ptr<Edge> e15 = make_shared<Edge>(v9, v14);
shared_ptr<Edge> e16 = make_shared<Edge>(v14, v10);
shared_ptr<Edge> e17 = make_shared<Edge>(v10, v15);
shared_ptr<Edge> e18 = make_shared<Edge>(v11, v16);
shared_ptr<Edge> e19 = make_shared<Edge>(v12, v17);
shared_ptr<Edge> e20 = make_shared<Edge>(v13, v18);
shared_ptr<Edge> e21 = make_shared<Edge>(v14, v19);
shared_ptr<Edge> e22 = make_shared<Edge>(v15, v20);
shared_ptr<Edge> e23 = make_shared<Edge>(v21, v1);
shared_ptr<Edge> e24 = make_shared<Edge>(v1, v22);
shared_ptr<Edge> e25 = make_shared<Edge>(v22, v17);
shared_ptr<Edge> e26 = make_shared<Edge>(v17, v23);
shared_ptr<Edge> e27 = make_shared<Edge>(v23, v18);
shared_ptr<Edge> e28 = make_shared<Edge>(v18, v14);
shared_ptr<Edge> e29 = make_shared<Edge>(v24, v19);
shared_ptr<Edge> e30 = make_shared<Edge>(v19, v25);
shared_ptr<Edge> e31 = make_shared<Edge>(v25, v20);
shared_ptr<Edge> e32 = make_shared<Edge>(v20, v26);
shared_ptr<Edge> e33 = make_shared<Edge>(v21, v27);
shared_ptr<Edge> e34 = make_shared<Edge>(v22, v28);
shared_ptr<Edge> e35 = make_shared<Edge>(v23, v29);
shared_ptr<Edge> e36 = make_shared<Edge>(v24, v30);
shared_ptr<Edge> e37 = make_shared<Edge>(v25, v31);
shared_ptr<Edge> e38 = make_shared<Edge>(v26, v32);
shared_ptr<Edge> e39 = make_shared<Edge>(v27, v33);
shared_ptr<Edge> e40 = make_shared<Edge>(v33, v28);
shared_ptr<Edge> e41 = make_shared<Edge>(v28, v34);
shared_ptr<Edge> e42 = make_shared<Edge>(v34, v29);
shared_ptr<Edge> e43 = make_shared<Edge>(v29, v35);
shared_ptr<Edge> e44 = make_shared<Edge>(v35, v30);
shared_ptr<Edge> e45 = make_shared<Edge>(v30, v36);
shared_ptr<Edge> e46 = make_shared<Edge>(v36, v31);
shared_ptr<Edge> e47 = make_shared<Edge>(v31, v37);
shared_ptr<Edge> e48 = make_shared<Edge>(v37, v32);
shared_ptr<Edge> e49 = make_shared<Edge>(v33, v38);
shared_ptr<Edge> e50 = make_shared<Edge>(v34, v39);
shared_ptr<Edge> e51 = make_shared<Edge>(v35, v40);
shared_ptr<Edge> e52 = make_shared<Edge>(v36, v41);
shared_ptr<Edge> e53 = make_shared<Edge>(v37, v42);
shared_ptr<Edge> e54 = make_shared<Edge>(v38, v43);
shared_ptr<Edge> e55 = make_shared<Edge>(v43, v39);
shared_ptr<Edge> e56 = make_shared<Edge>(v39, v44);
shared_ptr<Edge> e57 = make_shared<Edge>(v44, v40);
shared_ptr<Edge> e58 = make_shared<Edge>(v40, v45);
shared_ptr<Edge> e59 = make_shared<Edge>(v45, v41);
shared_ptr<Edge> e60 = make_shared<Edge>(v41, v46);
shared_ptr<Edge> e61 = make_shared<Edge>(v46, v42);
shared_ptr<Edge> e62 = make_shared<Edge>(v43, v47);
shared_ptr<Edge> e63 = make_shared<Edge>(v44, v48);
shared_ptr<Edge> e64 = make_shared<Edge>(v45, v49);
shared_ptr<Edge> e65 = make_shared<Edge>(v46, v50);
shared_ptr<Edge> e66 = make_shared<Edge>(v47, v51);
shared_ptr<Edge> e67 = make_shared<Edge>(v51, v48);
shared_ptr<Edge> e68 = make_shared<Edge>(v48, v52);
shared_ptr<Edge> e69 = make_shared<Edge>(v52, v49);
shared_ptr<Edge> e70 = make_shared<Edge>(v49, v53);
shared_ptr<Edge> e71 = make_shared<Edge>(v53, v50);

edges = {e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10,
         e11, e12, e13, e14, e15, e16, e17, e18, e19, e20,
         e21, e22, e23, e24, e25, e26, e27, e28, e29, e30,
         e31, e32, e33, e34, e35, e36, e37, e38, e39, e40,
         e41, e42, e43, e44, e45, e46, e47, e48, e49, e50,
         e51, e52, e53, e54, e55, e56, e57, e58, e59, e60,
         e61, e62, e63, e64, e65, e66, e67, e68, e69, e70,
         e71};

    tiles[0]->vertices.assign({v0, v4, v8, v12, v7, v3});
tiles[1]->vertices.assign({v1, v5, v9, v13, v8, v4});
tiles[2]->vertices.assign({v2, v6, v10, v14, v9, v5});
tiles[3]->vertices.assign({v7, v12, v17, v22, v16, v11});
tiles[4]->vertices.assign({v8, v13, v18, v23, v17, v12});
tiles[5]->vertices.assign({v9, v14, v19, v24, v18, v13});
tiles[6]->vertices.assign({v10, v15, v20, v25, v19, v14});
tiles[7]->vertices.assign({v16, v22, v28, v33, v27, v21});
tiles[8]->vertices.assign({v17, v23, v29, v34, v28, v22});
tiles[9]->vertices.assign({v18, v24, v30, v35, v29, v23});
tiles[10]->vertices.assign({v19, v25, v31, v36, v30, v24});
tiles[11]->vertices.assign({v20, v26, v32, v37, v31, v25});
tiles[12]->vertices.assign({v28, v34, v39, v43, v38, v33});
tiles[13]->vertices.assign({v29, v35, v40, v44, v39, v34});
tiles[14]->vertices.assign({v30, v36, v41, v45, v40, v35});
tiles[15]->vertices.assign({v31, v37, v42, v46, v41, v36});
tiles[16]->vertices.assign({v39, v44, v48, v51, v47, v43});
tiles[17]->vertices.assign({v40, v45, v49, v52, v48, v44});
tiles[18]->vertices.assign({v41, v46, v50, v53, v49, v45});

v0->edges.assign({e0, e1});
v1->edges.assign({e2, e3});
v2->edges.assign({e4, e5});
v3->edges.assign({e0, e6});
v4->edges.assign({e1, e7, e2});
v5->edges.assign({e3, e8, e4});
v6->edges.assign({e5, e9});
v7->edges.assign({e6, e10, e11});
v8->edges.assign({e7, e12, e13});
v9->edges.assign({e8, e14, e15});
v10->edges.assign({e9, e16, e17});
v11->edges.assign({e10, e18});
v12->edges.assign({e11, e19, e12});
v13->edges.assign({e13, e20, e14});
v14->edges.assign({e15, e21, e16});
v15->edges.assign({e17, e22});
v16->edges.assign({e18, e23, e24});
v17->edges.assign({e19, e25, e26});
v18->edges.assign({e20, e27, e28});
v19->edges.assign({e21, e29, e30});
v20->edges.assign({e22, e31, e32});
v21->edges.assign({e23, e33});
v22->edges.assign({e24, e34, e25});
v23->edges.assign({e26, e35, e27});
v24->edges.assign({e28, e36, e29});
v25->edges.assign({e30, e37, e31});
v26->edges.assign({e32, e38});
v27->edges.assign({e33, e39});
v28->edges.assign({e34, e40, e41});
v29->edges.assign({e35, e42, e43});
v30->edges.assign({e36, e44, e45});
v31->edges.assign({e37, e46, e47});
v32->edges.assign({e38, e48});
v33->edges.assign({e39, e49, e40});
v34->edges.assign({e41, e50, e42});
v35->edges.assign({e43, e51, e44});
v36->edges.assign({e45, e52, e46});
v37->edges.assign({e47, e53, e48});
v38->edges.assign({e49, e54});
v39->edges.assign({e50, e55, e56});
v40->edges.assign({e51, e57, e58});
v41->edges.assign({e52, e59, e60});
v42->edges.assign({e53, e61});
v43->edges.assign({e54, e62, e55});
v44->edges.assign({e56, e63, e57});
v45->edges.assign({e58, e64, e59});
v46->edges.assign({e60, e65, e61});
v47->edges.assign({e62, e66});
v48->edges.assign({e63, e67, e68});
v49->edges.assign({e69, e64, e70});
v50->edges.assign({e65, e71});
v51->edges.assign({e66, e67});
v52->edges.assign({e68, e69});
v53->edges.assign({e70, e71});

v0->tiles.assign({tiles[0]});
v1->tiles.assign({tiles[1]});
v2->tiles.assign({tiles[2]});
v3->tiles.assign({tiles[0]});
v4->tiles.assign({tiles[0], tiles[1]});
v5->tiles.assign({tiles[1], tiles[2]});
v6->tiles.assign({tiles[2]});
v7->tiles.assign({tiles[0], tiles[3]});
v8->tiles.assign({tiles[0], tiles[1], tiles[4]});
v9->tiles.assign({tiles[1], tiles[2], tiles[5]});
v10->tiles.assign({tiles[2], tiles[6]});
v11->tiles.assign({tiles[3]});
v12->tiles.assign({tiles[0], tiles[3], tiles[4]});
v13->tiles.assign({tiles[1], tiles[4], tiles[5]});
v14->tiles.assign({tiles[2], tiles[5], tiles[6]});
v15->tiles.assign({tiles[6]});
v16->tiles.assign({tiles[3], tiles[7]});
v17->tiles.assign({tiles[3], tiles[4], tiles[8]});
v18->tiles.assign({tiles[4], tiles[5], tiles[9]});
v19->tiles.assign({tiles[5], tiles[6], tiles[10]});
v20->tiles.assign({tiles[6], tiles[11]});
v21->tiles.assign({tiles[7]});
v22->tiles.assign({tiles[3], tiles[7], tiles[8]});
v23->tiles.assign({tiles[4], tiles[8], tiles[9]});
v24->tiles.assign({tiles[5], tiles[9], tiles[10]});
v25->tiles.assign({tiles[6], tiles[10], tiles[11]});
v26->tiles.assign({tiles[11]});
v27->tiles.assign({tiles[7]});
v28->tiles.assign({tiles[7], tiles[8], tiles[12]});
v29->tiles.assign({tiles[8], tiles[9], tiles[13]});
v30->tiles.assign({tiles[9], tiles[10], tiles[14]});
v31->tiles.assign({tiles[10], tiles[11], tiles[15]});
v32->tiles.assign({tiles[11]});
v33->tiles.assign({tiles[7], tiles[12]});
v34->tiles.assign({tiles[8], tiles[12], tiles[13]});
v35->tiles.assign({tiles[9], tiles[13], tiles[14]});
v36->tiles.assign({tiles[10], tiles[14], tiles[15]});
v37->tiles.assign({tiles[11], tiles[15]});
v38->tiles.assign({tiles[12]});
v39->tiles.assign({tiles[12], tiles[13], tiles[16]});
v40->tiles.assign({tiles[13], tiles[14], tiles[17]});
v41->tiles.assign({tiles[14], tiles[15], tiles[18]});
v42->tiles.assign({tiles[15]});
v43->tiles.assign({tiles[12], tiles[16]});
v44->tiles.assign({tiles[13], tiles[16], tiles[17]});
v45->tiles.assign({tiles[14], tiles[17], tiles[18]});
v46->tiles.assign({tiles[15], tiles[18]});
v47->tiles.assign({tiles[16]});
v48->tiles.assign({tiles[16], tiles[17]});
v49->tiles.assign({tiles[17], tiles[18]});
v50->tiles.assign({tiles[18]});
v51->tiles.assign({tiles[16]});
v52->tiles.assign({tiles[17]});
v53->tiles.assign({tiles[18]});

}


void Board::printBoard() {

    cout << "            " << vertices[0]->emoji<< "      " << vertices[1]->emoji << "      " << vertices[2]->emoji << "\n"
         << "          " << edges[0]->getColor() << "/   " << edges[1]->getColor() << "\\  " << edges[2]->getColor() << "/   " << edges[3]->getColor() << "\\  " << edges[4]->getColor() << "/   " << edges[5]->getColor() << "\\\033[0m\n"
         << "         " << vertices[3]->emoji << "     " << vertices[4]->emoji << "      " << vertices[5]->emoji << "      " << vertices[6]->emoji << "\n"
         << "         " << edges[6]->getColor() << "| " << tiles[0]->resourceEmoji << edges[7]->getColor() << "  |" << "  " << tiles[1]->resourceEmoji << edges[8]->getColor() << "   |  " << tiles[2]->resourceEmoji << "  " << edges[9]->getColor() << "|\033[0m\n"
         << "         " << vertices[7]->emoji << "  " <<tiles[0]->number <<  "  " << vertices[8]->emoji << "   " <<tiles[1]->number<<  "   " << vertices[9]->emoji << "  " <<tiles[2]->number<<  "  " << vertices[10]->emoji << "\n"
         << "       " << edges[10]->getColor() << "/   " << edges[11]->getColor() << "\\ " << edges[12]->getColor() << "/   " << edges[13]->getColor() << "\\   " << edges[14]->getColor() << "/   " << edges[15]->getColor() << "\\  " << edges[16]->getColor() << "/   " << edges[17]->getColor() << "\\\033[0m\n"
         << "      " << vertices[11]->emoji << "     " << vertices[12]->emoji << "     " << vertices[13]->emoji << "       " << vertices[14]->emoji << "     " << vertices[15]->emoji << "\n"
         << "      " << edges[18]->getColor() << "| " << tiles[3]->resourceEmoji << edges[19]->getColor() << "  |  " << tiles[4]->resourceEmoji << edges[20]->getColor() << "  |  " << tiles[5]->resourceEmoji << edges[21]->getColor() << "  |  " << tiles[6]->resourceEmoji << "  " << edges[22]->getColor() << "|\033[0m\n"
         << "      " << vertices[16]->emoji << "  " <<tiles[3]->number<< " " << vertices[17]->emoji << "  " <<tiles[4]->number<< "  " << vertices[18]->emoji << "  " <<tiles[5]->number<< "    " << vertices[19]->emoji << "  " <<tiles[6]->number<< "   " << vertices[20]->emoji << "\n"
         << "    " << edges[23]->getColor() << "/   " << edges[24]->getColor() << "\\ " << edges[25]->getColor() << "/   " << edges[26]->getColor() << "\\   " << edges[27]->getColor() << "/   " << edges[28]->getColor() << "\\ " << edges[29]->getColor() << "/   " << edges[30]->getColor() << "\\  " << edges[31]->getColor() << "/   " << edges[32]->getColor() << "\\\033[0m\n"
         << "   " << vertices[21]->emoji << "     " << vertices[22]->emoji << "      " << vertices[23]->emoji << "      " << vertices[24]->emoji << "      " << vertices[25]->emoji << "     " << vertices[26]->emoji << "\n"
         << "   " << edges[33]->getColor() << "| " << tiles[7]->resourceEmoji << edges[34]->getColor() << "  |  " << tiles[8]->resourceEmoji << edges[35]->getColor() << "   |  " << tiles[9]->resourceEmoji << edges[36]->getColor() << "   | " << tiles[10]->resourceEmoji << edges[37]->getColor() << "  |  " <<tiles[11]->resourceEmoji << "  " << edges[38]->getColor() << "|\033[0m\n"
         << "   " << vertices[27]->emoji << "  " <<tiles[7]->number<<  "  " << vertices[28]->emoji << "  " <<tiles[8]->number<< "   " << vertices[29]->emoji << "  " <<tiles[9]->number<< "  " << vertices[30]->emoji << "  " <<tiles[10]->number<< "  " << vertices[31]->emoji << "  " <<tiles[11]->number<< "  " << vertices[32]->emoji << "\n"
         << "    " << edges[38]->getColor() << "\\  " << edges[40]->getColor() << "/  " << edges[41]->getColor() << "\\    " << edges[42]->getColor() << "/  " << edges[43]->getColor() << "\\  " << edges[44]->getColor() << "/   " << edges[45]->getColor() << "\\  " << edges[46]->getColor() << "/   " << edges[47]->getColor() << "\\  " << edges[48]->getColor() << "/\033[0m\n"
         << "     " << vertices[33]->emoji << "      " << vertices[34]->emoji << "      " << vertices[35]->emoji << "      " << vertices[36]->emoji << "       " << vertices[37]->emoji << "\n"
         << "      " << edges[49]->getColor() << "| " << tiles[12]->resourceEmoji << edges[50]->getColor() << "  |  " << tiles[13]->resourceEmoji << edges[51]->getColor() << "  |  " << tiles[14]->resourceEmoji << edges[52]->getColor() << "  |  " << tiles[15]->resourceEmoji << edges[53]->getColor() << "   |\033[0m\n"
         << "      " << vertices[38]->emoji << "  " <<tiles[12]->number<< "  " << vertices[39]->emoji << "   "  <<tiles[13]->number<< "  " << vertices[40]->emoji << "  "  <<tiles[14]->number<< "   " << vertices[41]->emoji << "   " <<tiles[15]->number<< "  " << vertices[42]->emoji << "\n"
         << "        " << edges[54]->getColor() << "\\  " << edges[55]->getColor() << "/   " << edges[56]->getColor() << "\\  " << edges[57]->getColor() << "/   " << edges[58]->getColor() << "\\  " << edges[59]->getColor() << "/  " << edges[60]->getColor() << "\\    " << edges[61]->getColor() << "/\033[0m\n"
         << "         " << vertices[43]->emoji << "      " << vertices[44]->emoji << "      " << vertices[45]->emoji << "       " << vertices[46]->emoji << "\n"
         << "          " << edges[62]->getColor() << "|  " << tiles[16]->resourceEmoji << edges[63]->getColor() << " |  " << tiles[17]->resourceEmoji << edges[64]->getColor() << "  |  " << tiles[18]->resourceEmoji << edges[65]->getColor() << "    |\033[0m\n"
         << "          " << vertices[47]->emoji << "  "  <<tiles[16]->number<< "  " << vertices[48]->emoji << "   " <<tiles[17]->number<< "  " << vertices[49]->emoji << "  " <<tiles[18]->number<< "  " << vertices[50]->emoji << "\n"
         << "           " << edges[66]->getColor() << "\\   " << edges[67]->getColor() << "/  " << edges[68]->getColor() << "\\   " << edges[69]->getColor() << "/  " << edges[70]->getColor() << "\\   " << edges[71]->getColor() << "/\033[0m\n"
         << "             " << vertices[51]->emoji << "      " << vertices[52]->emoji << "      " << vertices[53]->emoji<<"\n"
         << "     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

// vector<Resource> Board::getVertexResource(int v){
//     vector<Resource> resources;
//     for (auto &tile : vertices[v]->tiles) {
//         resources.push_back(tile->resource);
//     }
//     return resources;
// }

void Board::placeSettlement(Player* player, int vertexIndex, int turnCounter) {
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::invalid_argument("Invalid vertex index");
    }
    auto &vertex = vertices[vertexIndex];
    if (vertex->owner != nullptr) {
        throw std::invalid_argument("Vertex already occupied");
    }
    
    // Check that settlements are at least two edges apart
    for (auto &edge : vertex->edges) {
        for (auto &neighbourVertex : edge->vertices) {
            if (neighbourVertex != vertex && neighbourVertex->owner != nullptr) {
                throw std::invalid_argument("Settlements must be at least two edges apart");
            }
        }
    }

    if(turnCounter>0 && !hasConnectedRoad(player, vertexIndex)) {
        throw std::invalid_argument("No connected road");
    }

    vertex->owner = player;
    vertex->type = Building::SETTLEMENT;
    vertex->emoji =player->colorToANSICode() + "🏚" + "\033[0m";
    printBoard();
}

void Board::placeRoad(Player* player, int edgeIndex) {
    if (edgeIndex < 0 || edgeIndex >= edges.size()) {
        throw std::invalid_argument("Invalid edge index");
    }
    auto &edge = edges[edgeIndex];
    if (edge->owner != nullptr) {
        throw std::invalid_argument("Edge already occupied");
    }
    bool isConnected = false;
    for (auto &vertex : edge->vertices) {
        if (vertex->owner == player) {
            isConnected = true;
            break;
        }
        for (auto &connectedEdge : vertex->edges) {
            if (connectedEdge->owner == player) {
                isConnected = true;
                break;
            }
        }
        if (isConnected) {
            break;
        }
    }
    if (!isConnected) {
        throw std::invalid_argument("No connected road or settlement/city");
    }
    edge->owner = player;
    printBoard();
}

void Board::placeCity(Player* player, int vertexIndex) {
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::invalid_argument("Invalid vertex index");
    }
    auto &vertex = vertices[vertexIndex];
    if (vertex->owner != player || vertex->type != Building::SETTLEMENT) {
        throw std::invalid_argument("No settlement at this vertex");
    }
    vertex->type = Building::CITY;
    vertex->emoji = player->colorToANSICode() + "🏙" + "\033[0m";
    printBoard();
}

bool Board::hasConnectedRoad(Player* player, int vertexIndex) {
    if (vertexIndex < 0 || vertexIndex >= vertices.size()) {
        throw std::invalid_argument("Invalid vertex index");
    }
    auto &vertex = vertices[vertexIndex];

    // Check if the player has a connected road
    for (auto &connectedEdge : vertex->edges) {
        if (connectedEdge->owner == player) {
            return true;
        }
    }
    return false;
}

void Board::placeKnight(Player* player, int tileIndex) {
    auto tile = tiles[tileIndex];
    if (tile->robber) {
        cout<<"Tile already has a knight"<<endl;
        return;
    }
    tile->robber = true;
    printBoard();
}
