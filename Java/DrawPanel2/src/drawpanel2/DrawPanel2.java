/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package drawpanel2;

import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;


/**
 *
 * @author BlueZ
 */
public class DrawPanel2 extends JPanel {
    
    public DrawPanel2() {
        super();
        setBackground(Color.BLACK);
    }
    
    public void paintComponent(Graphics g) {
        
        int width = getWidth();
        int height = getHeight();
        
        super.paintComponent(g);
        
        for(int i = 0; i < width; i++) {
            g.setColor(Color.white);
            g.fillArc(i, height/2 , 30, 30, 0, 360);
        }
       
        
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("My Design");
        DrawPanel2 panel = new DrawPanel2();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600,500);
        frame.add(panel);
        frame.setVisible(true);
    }
    
}
