/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package team1073.smartdashboard.extensions.defense3;


import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import java.awt.event.ActionListener;
import javax.swing.JComboBox;

/**
 *
 * @author julia
 */
public class Defense3 extends StaticWidget {
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Defense3";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Defense 3");
    
    String[] defenses = {"nothing!", "portcullis", "cheval de fries", "moat", "ramparts", "drawbridge", "sally port", "rock wall", "rough terrain"};
    JComboBox pickDefense = new JComboBox(defenses);
    //pickDefense.setBounds(new Rectangle(0, 0, 100, 40));
    //pickDefense.setVisible(true);
    
    public static String defense3 = "";
    
    public Defense3() {
        
        /*mode.add("nothing!", 0);
        mode.add("portcullis", 1);
        mode.add("cheval de fries", 2);
        mode.add("moat", 3);
        mode.add("ramparts", 4);
        mode.add("drawbridge", 5);
        mode.add("sally port", 6);
        mode.add("rock wall", 7);
        mode.add("rough terrain", 8);*/
        
    }
    
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        // defenses 50" wide (1" = 4 pixels)
        pickDefense.setVisible(true);
        this.add(pickDefense);
        setPreferredSize(new Dimension(200, 288));
        
    }

    @Override
    public void propertyChanged(Property prprt) {
        setValue(prprt.getValue());
    }
    
    @Override
    protected void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D)g;
        //makes it less pixely
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        Dimension size = getSize();
        //allows g2.drawings to scale if(x&yvalues == %%)
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        double x = 200;
        double y = 288.0;        
        
        defense3 = (String)pickDefense.getSelectedItem();
        
        //drawBridge(g2);
        if(pickDefense.getSelectedItem() == "nothing!") {
            // do nothing
        }
        
        if(pickDefense.getSelectedItem() == "portcullis") {
            drawPortcullis(g2);
        }
        
        if(pickDefense.getSelectedItem() == "cheval de fries") {
            drawFries(g2);
        }
        
        if(pickDefense.getSelectedItem() == "moat") {
            drawMoat(g2);
        }
        
        if(pickDefense.getSelectedItem() == "ramparts") {
            drawRamparts(g2);
        }
        
        if(pickDefense.getSelectedItem() == "drawbridge") {
            drawBridge(g2);
        }
        
        if(pickDefense.getSelectedItem() == "sally port") {
            drawSallyPort(g2);
        }
        
        if(pickDefense.getSelectedItem() == "rock wall") {
            buildWall(g2);
        }
        
        if(pickDefense.getSelectedItem() == "rough terrain") {
            drawRoughTerrain(g2);
        }
        
    }
    
    public void drawPortcullis(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        Color c3 = new Color(130, 137, 147);    // post fill
        Color c4 = new Color(99, 103, 111);     // post outline
        Color c5 = new Color(83, 84, 85);       // top fill
        Color c6 = new Color(39, 39, 39);       // grid fill
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle leftpost = new Rectangle((int)(xtotal * (4.0/x)), (int)(ytotal * (60.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (216.0/y)));
        Rectangle rightpost = new Rectangle((int)(xtotal * (188.0/x)), (int)(ytotal * (60.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (216.0/y)));

        int[] xs1 = {(int)(xtotal * (4.0/x)), (int)(xtotal * (4.0/x)), 
                     (int)(xtotal * (22.0/x)), (int)(xtotal * (22.0/x)),
                     (int)(xtotal * (50.0/x)), (int)(xtotal * (50.0/x)),
                     (int)(xtotal * (86.0/x)), (int)(xtotal * (86.0/x)),
                     (int)(xtotal * (114.0/x)), (int)(xtotal * (114.0/x)),
                     (int)(xtotal * (150.0/x)), (int)(xtotal * (150.0/x)),
                     (int)(xtotal * (178.0/x)), (int)(xtotal * (178.0/x)),
                     (int)(xtotal * (196.0/x)), (int)(xtotal * (196.0/x)),
                     (int)(xtotal * (188.0/x)), (int)(xtotal * (150.0/x)),
                     (int)(xtotal * (50.0/x)), (int)(xtotal * (12.0/x))};
        
        int[] ys1 = {(int)(ytotal * (60.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (60.0/y)),
                     (int)(ytotal * (60.0/y)), (int)(ytotal * (36.0/y)),
                     (int)(ytotal * (36.0/y)), (int)(ytotal * (60.0/y))};
        
        Polygon top = new Polygon(xs1, ys1, 20);
        
        g2.setColor(c1);
        g2.fill(platform);
        
        g2.setColor(c2);
        g2.draw(platform);
        
        g2.setColor(c6);
        g2.fillRect((int)(xtotal * (39.0/x)), (int)(ytotal * (24.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (232.0/y)));
        g2.fillRect((int)(xtotal * (77.0/x)), (int)(ytotal * (24.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (232.0/y)));
        g2.fillRect((int)(xtotal * (115.0/x)), (int)(ytotal * (24.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (232.0/y)));
        g2.fillRect((int)(xtotal * (153.0/x)), (int)(ytotal * (24.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (232.0/y)));
        
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (248.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (8.0/y)));
        
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (200.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (152.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (104.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (56.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (8.0/y)));
        
        g2.setColor(c3);
        g2.fill(leftpost);
        g2.fill(rightpost);
        
        g2.setColor(c4);
        g2.draw(leftpost);
        g2.draw(rightpost);
        
        g2.setColor(c5);
        g2.fill(top);
        
    }
    
    public void drawFries(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        Color c3 = new Color(83, 50, 43);       // dark fill
        Color c4 = new Color(103, 64, 54);      // light fill
        Color c5 = new Color(63, 47, 43);       // dark lines
        Color c6 = new Color(101, 55, 46);      // light lines
        Color c7 = new Color(155, 155, 156);    // pie fill
        Color c8 = new Color(79, 83, 89);       // pie outline
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        
        Rectangle fry1 = new Rectangle((int)(xtotal * (4.0/x)), (int)(ytotal * (236.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (40.0/y)));
        Rectangle fry2 = new Rectangle((int)(xtotal * (52.0/x)), (int)(ytotal * (236.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (40.0/y)));
        Rectangle fry3 = new Rectangle((int)(xtotal * (100.0/x)), (int)(ytotal * (236.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (40.0/y)));
        Rectangle fry4 = new Rectangle((int)(xtotal * (148.0/x)), (int)(ytotal * (236.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (40.0/y)));
        
        Rectangle pipe1 = new Rectangle((int)(xtotal * (4.0/x)), (int)(ytotal * (252.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (8.0/y)));
        Rectangle pipe2 = new Rectangle((int)(xtotal * (100.0/x)), (int)(ytotal * (252.0/y)), (int)(xtotal * (48.0/x)), (int)(ytotal * (8.0/y)));
        
        g2.setColor(c1);
        g2.fill(platform);
        
        g2.setColor(c2);
        g2.draw(platform);
        
        g2.setColor(c3);
        g2.fill(fry1);
        g2.fill(fry3);
        
        g2.setColor(c5);
        g2.draw(fry1);
        g2.draw(fry3);
        
        g2.setColor(c4);
        g2.fill(fry2);
        g2.fill(fry4);
        
        g2.setColor(c6);
        g2.draw(fry2);
        g2.draw(fry4);
        
        g2.setColor(c7);
        g2.fill(pipe1);
        g2.fill(pipe2);
        
        g2.setColor(c8);
        g2.draw(pipe1);
        g2.draw(pipe2);
        
    }
    
    public void drawMoat(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle moatwall = new Rectangle(0, (int)(ytotal * (266.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (10.0/y)));
        
        g2.setColor(c1);
        g2.fill(platform);
        g2.fill(moatwall);
        
        g2.setColor(c2);
        g2.draw(platform);
        g2.draw(moatwall);
        
    }
    
    public void drawRamparts(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle leftpart = new Rectangle(((int)(xtotal * (4.0/x))), (int)(ytotal * (268.0/y)), (int)(xtotal * (96.0/x)), (int)(ytotal * (8.0/y)));
        Rectangle rightpart = new Rectangle((int)(xtotal * (100.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (96.0/x)), (int)(ytotal * (8.0/y)));
        // 2" high
        g2.setColor(c1);
        g2.fill(platform);
        g2.fill(leftpart);
        g2.fill(rightpart);
        
        g2.setColor(c2);
        g2.draw(platform);
        g2.draw(leftpart);
        g2.draw(rightpart);
        
    }
    
    public void drawBridge(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        Color c3 = new Color(130, 137, 147);    // post fill
        Color c4 = new Color(99, 103, 111);     // post outline
        Color c5 = new Color(83, 84, 85);       // top fill
        Color c6 = new Color(39, 39, 39);       // grid fill
        Color c7 = new Color(83, 54, 47);       // drawbridge fill
        Color c8 = new Color(48, 31, 27);
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle leftpost = new Rectangle((int)(xtotal * (4.0/x)), (int)(ytotal * (60.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (216.0/y)));
        Rectangle rightpost = new Rectangle((int)(xtotal * (188.0/x)), (int)(ytotal * (60.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (216.0/y)));

        int[] xs1 = {(int)(xtotal * (4.0/x)), (int)(xtotal * (4.0/x)), 
                     (int)(xtotal * (22.0/x)), (int)(xtotal * (22.0/x)),
                     (int)(xtotal * (50.0/x)), (int)(xtotal * (50.0/x)),
                     (int)(xtotal * (86.0/x)), (int)(xtotal * (86.0/x)),
                     (int)(xtotal * (114.0/x)), (int)(xtotal * (114.0/x)),
                     (int)(xtotal * (150.0/x)), (int)(xtotal * (150.0/x)),
                     (int)(xtotal * (178.0/x)), (int)(xtotal * (178.0/x)),
                     (int)(xtotal * (196.0/x)), (int)(xtotal * (196.0/x)),
                     (int)(xtotal * (188.0/x)), (int)(xtotal * (150.0/x)),
                     (int)(xtotal * (50.0/x)), (int)(xtotal * (12.0/x))};
        
        int[] ys1 = {(int)(ytotal * (60.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (20.0/y)),
                     (int)(ytotal * (20.0/y)), (int)(ytotal * (0.0/y)),
                     (int)(ytotal * (0.0/y)), (int)(ytotal * (60.0/y)),
                     (int)(ytotal * (60.0/y)), (int)(ytotal * (36.0/y)),
                     (int)(ytotal * (36.0/y)), (int)(ytotal * (60.0/y))};
        
        Polygon top = new Polygon(xs1, ys1, 20);
        
        g2.setColor(c1);
        g2.fill(platform);
        
        g2.setColor(c2);
        g2.draw(platform);
        
        g2.setColor(c3);
        g2.fill(leftpost);
        g2.fill(rightpost);
        
        g2.setColor(c4);
        g2.draw(leftpost);
        g2.draw(rightpost);
        
        g2.setColor(c5);
        g2.fill(top);
                
        g2.setColor(c7);
        g2.fillRect((int)(xtotal * (12.0/x)), (int)(ytotal * (128.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (148.0/y)));
        
        g2.setColor(c8);
        g2.drawRect((int)(xtotal * (12.0/x)), (int)(ytotal * (128.0/y)), (int)(xtotal * (176.0/x)), (int)(ytotal * (148.0/y)));
        
    }
    
    public void drawSallyPort(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        Color c3 = new Color(83, 54, 47);       // door fill
        Color c4 = new Color(48, 31, 27);
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));

        g2.setColor(c1);
        g2.fill(platform);
        
        g2.setColor(c2);
        g2.draw(platform);
        
        g2.setColor(c3);
        g2.fillRect(0, (int)(ytotal * (176.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (100.0/y)));
     
        g2.setColor(c4);
        g2.drawRect(0, (int)(ytotal * (176.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (100.0/y)));
        
    }
    
    public void buildWall(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle wall = new Rectangle(0, (int)(ytotal * (256.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (20.0/y)));
        
        g2.setColor(c1);
        g2.fill(platform);
        g2.fill(wall);
        
        g2.setColor(c2);
        g2.draw(platform);
        g2.draw(wall);
        
    }
    
    public void drawRoughTerrain(Graphics2D g2) {
        
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;   // 50"
        double y = 288.0;   // 6'
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        
        Rectangle platform = new Rectangle(0, (int)(ytotal * (276.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));

        g2.setColor(c1);
        g2.fill(platform);
        
        g2.setColor(c2);
        g2.draw(platform);
        
        // row 1
        g2.setColor(c1);
        g2.fillRect((int)(xtotal * (13.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (31.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (49.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (67.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (85.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (103.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (121.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (139.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (157.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (175.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        
        g2.setColor(c2);
        g2.drawRect((int)(xtotal * (13.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (31.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (49.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (67.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (85.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (103.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (121.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (139.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (157.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (175.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        
        
        // row 2
        g2.setColor(c1);
        g2.fillRect((int)(xtotal * (4.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (22.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (40.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (58.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (76.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (94.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (112.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (130.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (148.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (166.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (184.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));

        g2.setColor(c2);
        g2.drawRect((int)(xtotal * (4.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (22.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (40.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (58.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (76.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (94.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (112.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (130.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (148.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (166.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (184.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        
        // row 3
        g2.setColor(c1);
        g2.fillRect((int)(xtotal * (13.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (31.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (49.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (67.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (85.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (103.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.fillRect((int)(xtotal * (121.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (139.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.fillRect((int)(xtotal * (157.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.fillRect((int)(xtotal * (175.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        
        g2.setColor(c2);
        g2.drawRect((int)(xtotal * (13.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (31.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (49.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (67.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (85.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (103.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        g2.drawRect((int)(xtotal * (121.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (139.0/x)), (int)(ytotal * (272.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (4.0/y)));
        g2.drawRect((int)(xtotal * (157.0/x)), (int)(ytotal * (268.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (8.0/y)));
        g2.drawRect((int)(xtotal * (175.0/x)), (int)(ytotal * (264.0/y)), (int)(xtotal * (12.0/x)), (int)(ytotal * (12.0/y)));
        
        // blank
        //g2.fillRect((int)(xtotal * (0.0/x)), (int)(ytotal * (0.0/y)), (int)(xtotal * (0.0/x)), (int)(ytotal * (0.0/y)));

    }
    
}