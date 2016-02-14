/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.laucherangle;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;

//"extends Widget" is super-duper important
public class LaucherAngle extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "LaucherAngle";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "LaucherAngle");

    
    public LaucherAngle() {
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
        setPreferredSize(new Dimension(200, 200));
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
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        //establish default colors
        Color c1 = new Color(255, 255, 255);    // a color
        
        //getAngle();
        double angle = Math.PI / 4;
        
        double sinangle = Math.sin(angle);
        double cosangle = Math.cos(angle);
        
        //Line xaxis = new Line(0, 50, 100, 50);
        g2.drawLine(0, 200, 200, 200);
        g2.drawLine(0, 200, (int)(100.0 * cosangle), (int)(ytotal - (100.0 * sinangle)));
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    private void drawLaucher(double sinangle, double cosangle, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        
        
        
    }
    
}