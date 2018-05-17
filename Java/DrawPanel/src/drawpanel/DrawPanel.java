/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package drawpanel;

import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author BlueZ
 */
public class DrawPanel extends JPanel {
    
    DrawPanel() {
        super();
        setBackground(Color.black);
    }
    
    public void paintComponent(Graphics g) {
        
        int width = getWidth(); 
        int height = getHeight();
        
        super.paintComponent(g);
        
        g.setColor(Color.white);
        
        int sAngle = 0, throughAngle = 180, radius = 0, xPoint = 0, yPoint = 0;
        
        for(int i = 0; i <= 50; i++) {
            radius = radius + 5;
            if(i % 2 == 0) {
                sAngle = 180;
                xPoint = width/2-radius;
                yPoint = height/2-radius;
            }
            else {
                sAngle = 0;
                xPoint = width/2-radius-5;
                yPoint = height/2-radius;
            }
            g.drawArc(xPoint, yPoint, 2*radius, 2*radius, sAngle, throughAngle);
            
        }
       
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("My Design");
        DrawPanel panel = new DrawPanel();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(panel);
        frame.setSize(500, 400);
        frame.setVisible(true);
    }
    
    
}
