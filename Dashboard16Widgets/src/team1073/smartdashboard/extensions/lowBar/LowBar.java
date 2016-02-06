/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package team1073.smartdashboard.extensions.lowBar;

import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;

/**
 *
 * @author julia
 */
public class LowBar extends StaticWidget {
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "LowBar";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Low Bar");
    
    public LowBar() {
        mode.add("full", 0);
        mode.add("half", 1);
        mode.add("zero", 2);
    }
    
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        // defenses 50" wide (1" = 4 pixels)
        setPreferredSize(new Dimension(200, 80));
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
        
        drawLowBar(g2);
        
        if(value == 0) {
            
        }
        
        if(value == 1) {
            
        }
        
        if(value == 2) {
            
        }
        
    }
    
    private void drawLowBar(Graphics2D g2) {
        //allows g2.drawings to scale if(x&yvalues == %%)
        double x = 200.0;
        double y = 80.0;
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        
        Color c1 = new Color(169, 169, 169);    // platform fill
        Color c2 = new Color(126, 126, 126);    // platform outline
        Color c3 = new Color(136, 141, 151);    // pole fill
        Color c4 = new Color(89, 94, 101);      // pole outline
        Color c5 = new Color(35, 35, 35);       // flap fill
        Color c6 = new Color(28, 28, 28);       // flap top
        Color c7 = new Color(71, 71, 71);       // flap line
        
        // 50" * 3"
        Rectangle platform = new Rectangle(0, (int)(ytotal * (68.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle leftpole = new Rectangle((int)(xtotal * (4.0/x)), 0, (int)(xtotal * (4.0/x)), (int)(ytotal * (68.0/y)));
        Rectangle rightpole = new Rectangle((int)(xtotal * (192.0/x)), 0, (int)(xtotal * (4.0/x)), (int)(ytotal * (68.0/y)));
        Rectangle flap = new Rectangle((int)(xtotal * (12.0/x)), 0, (int)(xtotal * (176.0/x)), (int)(ytotal * (62.0/y)));
        Rectangle flaptop = new Rectangle((int)(xtotal * (12.0/x)), 0, (int)(xtotal * (176.0/x)), (int)(ytotal * (12.0/y)));

        
        int[] xs1 = {(int)(xtotal * (4.0/x)), (int)(xtotal * (196.0/x)), (int)(xtotal * (192.0/x)), (int)(xtotal * (8.0/x))};
        int[] ys1 = {0, 0, (int)(ytotal * (4.0/y)), (int)(ytotal * (4.0/y))};
        Polygon bar = new Polygon(xs1, ys1, 4);
        
        g2.setColor(c1);
        g2.fill(platform);
        g2.setColor(c2);
        g2.draw(platform);
        
        g2.setColor(c3);
        g2.fill(leftpole);
        g2.fill(rightpole);
        
        g2.setColor(c4);
        g2.draw(rightpole);
        g2.draw(leftpole);
        
        g2.setColor(c3);
        g2.fill(bar);
        
        g2.setColor(c4);
        g2.draw(bar);
        
        g2.setColor(c5);
        g2.fill(flap);
        
        g2.setColor(c6);
        g2.fill(flaptop);
        
        g2.setColor(c7);
        g2.drawLine((int)(xtotal * (12.0/x)), (int)(ytotal * (54.0/y)), (int)(xtotal * (186.0/x)), (int)(ytotal * (54.0/y)));
        g2.drawLine((int)(xtotal * (12.0/x)), (int)(ytotal * (46.0/y)), (int)(xtotal * (186.0/x)), (int)(ytotal * (46.0/y)));

    }
    
    public void getHealth(double health, Graphics2D g2) {
        
    }
    
}
