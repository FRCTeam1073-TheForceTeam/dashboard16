/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.crosshair;
// lines 18 and 38 have instructions on what to do for testing the dashboard with the robot

// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;

// "extends Widget" is super-duper important
// "extends StaticWidget" is for non-robot testing, "extends Widget" is for testing with the robot
public class Crosshair extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Crosshair";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Crosshair");

    
    public Crosshair() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        
    }
    
    // "//////////@Override" is for non-robot testing, "@Override" is for testing with the robot
    ////////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        setPreferredSize(new Dimension(40, 40));
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
        //establish default colors
        Color c1 = new Color(255, 255, 255);    //a color
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    private void drawCrosshair(Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        
        // 40 X 40
        double x = 40.0;
        double y = 40.0;
        
        Color c1 = new Color(255, 0, 0);
        
        g2.drawRect((int)(xtotal * (25.0/x)), 0, (int)(xtotal * (10.0/x)), (int)(ytotal * (40.0/x)));
        g2.drawRect(0, (int)(ytotal * (25.0/y)), (int)(xtotal * (40.0/x)), (int)(ytotal * (10.0/x)));

    }
    
}