/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.defmanippid;
// lines 18 and 38 have instructions on what to do for testing the dashboard with the robot

// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import java.awt.geom.Rectangle2D;

// "extends Widget" is super-duper important
// "extends StaticWidget" is for non-robot testing, "extends Widget" is for testing with the robot
public class DefPID extends Widget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.BOOLEAN};
    public static final String NAME = "DefPID";
    private boolean value = false;
    public final MultiProperty mode = new MultiProperty(this, "DefPID");
    boolean isPID = false;
    
    public DefPID() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        
    }
    
    // "//////////@Override" is for non-robot testing, "@Override" is for testing with the robot
    @Override
    public void setValue(Object o) {
        this.value = ((Boolean) o);
        isPID = value;
        repaint();
    }

    @Override
    public void init() {
        setPreferredSize(new Dimension(300, 50));
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
        Color c1 = new Color(0, 0, 0);    //a color
        //GradientPaint gp = new GradientPaint(0, 0, c2, size.width/2, 0, c3);
        String num = ""+value;
        
        //g2.setPaint(gp);
        //g2.fill(new Rectangle2D.Double(0, 0, size.width, size.height));
        g2.setPaint(c1);
        g2.setFont(new Font("Default", Font.BOLD, 18));
        g2.drawString("Defense Manipulator PID:  " + isPID, 0, size.height - 1);
        
    }
    
}