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
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        Color c1 = new Color(148, 148, 148);    // platform outline
        Color c2 = new Color(177, 177, 177);    // platform fill
        Color c3 = new Color(31, 31, 31);       // flap outline
        Color c4 = new Color(54, 54, 54);       // flap fill
        
        // 50" * 3"
        Rectangle platform = new Rectangle(0, (int)(ytotal * (68.0/y)), (int)(xtotal * (200.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle leftpole = new Rectangle((int)(xtotal * (8.0/x)), 0, (int)(xtotal * (4.0/x)), (int)(ytotal * (68.0/y)));
        Rectangle rightpole = new Rectangle((int)(xtotal * (180.0/x)), 0, (int)(xtotal * (4.0/x)), (int)(ytotal * (68.0/y)));
        Rectangle pole = new Rectangle((int)(xtotal * (8.0/x)), 0, (int)(xtotal * (184.0/x)), (int)(ytotal * (4.0/y)));
        
        g2.setColor(c2);
        g2.fill(platform);
        g2.fill(leftpole);
        g2.fill(rightpole);
        g2.fill(pole);
        
        g2.setColor(c1);
        g2.draw(platform);
        g2.draw(leftpole);
        g2.draw(rightpole);
        g2.draw(pole);
        
    }
    
    public void getHealth(double health, Graphics2D g2) {
        
    }
    
}
