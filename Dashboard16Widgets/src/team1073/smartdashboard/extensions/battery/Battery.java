/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.battery;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import java.awt.geom.*;

//"extends Widget" is super-duper important
public class Battery extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Battery";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Battery Percent");

    
    public Battery() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        
    }
    
    ////////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        setPreferredSize(new Dimension(200, 100));
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
        double xTotal = (int)size.getWidth();
        double yTotal = (int)size.getHeight();
        //establish default colors
        Color c1 = new Color(255, 255, 255);    //a color
        
        drawBattery(0.0, g2);
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    private void drawBattery(double percentPower, Graphics2D g2){
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        double x = 200;
        double y = 100;
        
        Color c1 = new Color(255, 255, 255);
        Color c2 = new Color(83, 255, 47);
        
        RoundRectangle2D.Double outline1 = new RoundRectangle2D.Double(0, 0, (int)(xtotal * (185.0/x)), (int)(ytotal * (100.0/y)), (int)(xtotal * (10.0/x)), (int)(ytotal * (10.0/y)));
        RoundRectangle2D.Double outline2 = new RoundRectangle2D.Double((int)(xtotal * (1.0/x)), (int)(ytotal * (1.0/y)), (int)(xtotal * (183.0/x)), (int)(ytotal * (98.0/y)), (int)(xtotal * (8.0/x)), (int)(ytotal * (8.0/y)));
        RoundRectangle2D.Double outline3 = new RoundRectangle2D.Double((int)(xtotal * (2.0/x)), (int)(ytotal * (2.0/y)), (int)(xtotal * (181.0/x)), (int)(ytotal * (96.0/y)), (int)(xtotal * (6.0/x)), (int)(ytotal * (6.0/y)));
        RoundRectangle2D.Double outline4 = new RoundRectangle2D.Double((int)(xtotal * (3.0/x)), (int)(ytotal * (3.0/y)), (int)(xtotal * (179.0/x)), (int)(ytotal * (94.0/y)), (int)(xtotal * (4.0/x)), (int)(ytotal * (4.0/y)));
        
        Rectangle percentbattery = new Rectangle((int)(xtotal * (2.0/x)), (int)(ytotal * (2.0/y)), (int)(xtotal * (181.0/x)), (int)(ytotal * (96.0/y)));
        
        RoundRectangle2D.Double end1 = new RoundRectangle2D.Double(0, 0, (int)(xtotal * (185.0/x)), (int)(ytotal * (100.0/y)), (int)(xtotal * (5.0/x)), (int)(ytotal * (5.0/y)));
        RoundRectangle2D.Double end2 = new RoundRectangle2D.Double(0, 0, (int)(xtotal * (185.0/x)), (int)(ytotal * (100.0/y)), (int)(xtotal * (5.0/x)), (int)(ytotal * (5.0/y)));
        
        g2.setColor(c2);
        g2.fill(percentbattery);
        
        g2.setColor(c1);
        g2.draw(outline1);
        g2.draw(outline2);
        g2.draw(outline3);
        g2.draw(outline4);
        
    }
    
}