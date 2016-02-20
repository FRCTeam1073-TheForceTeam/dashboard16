/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.robot;


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
public class RobotMechanisms extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Robot";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Robot Mechanisms");

    
    public RobotMechanisms() {
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
        setPreferredSize(new Dimension(384, 384));
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
        Color c1 = new Color(255, 255, 255);    //a color
        
        //double laucherangle = getAngle();
        // will be in degrees
        double laucherangle = 45.0;
        
        //drawLaucher(laucherangle, g2);
        
        drawRobot(g2);
        
        drawDefenseManipulator(15.0, true, g2);
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    private void drawRobot(Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        double x = 384.0;
        double y = 384.0;
        
        Color c1 = new Color(62, 63, 65);       // frame fill
        Color c2 = new Color(38, 39, 40);       // frame outline
        Color c3 = new Color(151, 152, 157);    // bumper thing
        Color c4 = new Color(123, 124, 130);    // bumper thing outline
        Color c5 = new Color(129, 134, 156);    // wheel inside
        Color c6 = new Color(105, 109, 129);    // wheel outside
        
        double xpos1 = getWidth() - 256.0;
        double ypos1 = getHeight() - 108.0;
        int[] xs1 = {(int)(xtotal * (xpos1/x)), (int)(xtotal * ((256.0 + xpos1)/x)),
                     (int)(xtotal * ((256.0 + xpos1)/x)), (int)(xtotal * ((224.0 + xpos1)/x)),
                     (int)(xtotal * ((32.0 + xpos1)/x)), (int)(xtotal * ((xpos1)/x))};
        int[] ys1 = {(int)(ytotal * (ypos1/y)), (int)(ytotal * (ypos1/y)),
                     (int)(ytotal * ((48.0 + ypos1)/y)), (int)(ytotal * ((80.0 + ypos1)/y)),
                     (int)(ytotal * ((80.0 + ypos1)/y)), (int)(ytotal * ((48.0 + ypos1)/y))};
        
        Polygon drivetrainframe = new Polygon(xs1, ys1, 6);
        
        Rectangle bumperthing1 = new Rectangle((int)(xtotal * (xpos1/x)), (int)(ytotal * ((24.0 + ypos1)/x)), (int)(xtotal * (256.0/x)), (int)(ytotal * (8.0/x)));
        Rectangle bumperthing2 = new Rectangle((int)(xtotal * (xpos1/x)), (int)(ytotal * ((40.0 + ypos1)/x)), (int)(xtotal * (256.0/x)), (int)(ytotal * (8.0/x)));
        
        Ellipse2D.Double wheel1 = new Ellipse2D.Double((int)(xtotal * ((8.0 + xpos1)/x)), (int)(ytotal * ((44.0 + ypos1)/x)), (int)(xtotal * (64.0/x)), (int)(ytotal * (64.0/x)));
        Ellipse2D.Double wheel2 = new Ellipse2D.Double((int)(xtotal * ((96.0 + xpos1)/x)), (int)(ytotal * ((44.0 + ypos1)/x)), (int)(xtotal * (64.0/x)), (int)(ytotal * (64.0/x)));
        Ellipse2D.Double wheel3 = new Ellipse2D.Double((int)(xtotal * ((184.0 + xpos1)/x)), (int)(ytotal * ((44.0 + ypos1)/x)), (int)(xtotal * (64.0/x)), (int)(ytotal * (64.0/x)));
        
        g2.setColor(c6);
        g2.fill(wheel1);
        g2.fill(wheel2);
        g2.fill(wheel3);
        
        /*g2.setColor(c5);
        g2.fill(wheel1);
        g2.fill(wheel2);
        g2.fill(wheel3);*/
        
        g2.setColor(c3);
        g2.fill(drivetrainframe);
        
        g2.setColor(c4);
        g2.draw(drivetrainframe);
        
        g2.setColor(c3);
        g2.fill(bumperthing1);
        g2.fill(bumperthing2);
        
        g2.setColor(c4);
        g2.draw(bumperthing1);
        g2.draw(bumperthing2);
        
    }
    
    private void drawLaucher(double angle, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        double x = 384.0;
        double y = 384.0;
        
        double cosangle = Math.cos(Math.toRadians(angle));
        double sinangle = Math.sin(Math.toRadians(angle));
        
        g2.drawLine(0, 200, 200, 200);
        g2.drawLine(384, 384, (int)(xtotal - (100.0 * cosangle)), (int)(ytotal - (100.0 * sinangle)));
        
    }
    
    private void drawDefenseManipulator(double angle, boolean piston, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        double x = 0;
        double y = 0;
        int xc = 0;
        int yc = 0;
        
        double xpos1 = getWidth() - 256.0;
        //double xpos1 = 100.0;
        double ypos1 = (getHeight() - 108.0) + 48.0;
        
        // 15 + 10
        // angle is screwy and works nicely with orientation
        
        double sinangle = Math.sin(Math.toRadians(angle));
        double cosangle = Math.cos(Math.toRadians(angle));
        
        g2.setColor(Color.RED);
        g2.drawLine((int)(xpos1 - 60.0), 10, (int)(xpos1 - 60.0), 400);
        
        // works
        g2.setColor(Color.BLACK);
        g2.drawLine((int)xpos1, (int)ypos1, (int)(xpos1 - (60.0 * cosangle)), (int)(ypos1 - (60.0 * sinangle)));
        
        // works
        if(piston == true) {
            g2.setColor(Color.GRAY);
            g2.drawLine((int)(xpos1 - (60.0 * cosangle)), (int)(ypos1 - (60.0 * sinangle)), (int)((xpos1 - (40.0 * cosangle)) - (60.0 * cosangle)), (int)((ypos1 - (40.0 * sinangle)) - (60.0 * sinangle)));
        }
        
        /*
         1    2
         3    4
         3&4 direct trig values
        */
        
        int[] xs1 = {(int)(xtotal * ((xc + 0.0)/x)), (int)(xtotal * ((xc + 0.0)/x)),
                     (int)(xtotal * ((xc + 0.0)/x)), (int)(xtotal * ((xc + 0.0)/x))};
        int[] ys1 = {(int)(ytotal * ((yc + 0.0)/y)), (int)(ytotal * ((yc + 0.0)/y)),
                     (int)(ytotal * ((yc + 0.0)/y)), (int)(ytotal * ((yc + 0.0)/y))};
        
    }
    
}