package com.teamg.entregas;

public class Teste {

    public static void main(String[] args) {
        Tree arvore1 = new Tree(new NodeDisplay() {
            @Override
            public void display(String text) {
                return;
            }
        });

        arvore1 = arvore1.createMap(new NodeDisplay() {
            @Override
            public void display(String text) {
                return;
            }
        });
        arvore1.showMarginais();
        arvore1.showAvenidas();
        arvore1.showRuas();

        arvore1.findRoute(new String("Rua 15"));
        arvore1.closeNode("Avenida A");
        arvore1.findRoute(new String("Rua 15"));
    }
}
