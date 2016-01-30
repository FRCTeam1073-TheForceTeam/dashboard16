/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package team1073.smartdashboard.extensions.defense2;


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
public class Defense2 extends StaticWidget {
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Defense2";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Defense 2");
    
    public Defense2() {
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
        //allows g2.drawings to scale if(x&yvalues == %%)
        int xtotal = (int)size.getWidth();
        int ytotal = (int)size.getHeight();
        int x = 200;
        int y = 80;
        //g2.fillRect(0, 0, xtotal / 2, ytotal / 2);
        
        //Rectangle platform = new Rectangle(0, (int)(ytotal * (68/80)), (int)(xtotal * (200/200)), (int)(ytotal * (12/80)));
        //Rectangle platform = new Rectangle(0, ytotal * (68/y), xtotal * (200/x), ytotal * (12/y));
        //Rectangle platform = new Rectangle(0, (int)(80 * (68/80)), x * (200/x), (int)(80 * (12/80)));
        /*Rectangle platform = new Rectangle(0, 68, x * (200/x), 12);
        g2.setColor(new Color(0, 0, 0));
        g2.draw(platform);*/
        
        if(value == 0) {
            
        }
        
        if(value == 1) {
            
        }
        
        if(value == 2) {
            
        }
        
    }
    
}