/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.time;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import static edu.wpi.first.wpilibj.Timer.getMatchTime;
import java.awt.*;

//"extends Widget" is super-duper important
public class MatchTime extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Time";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Match Time");

    
    public MatchTime() {
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
        setPreferredSize(new Dimension(225, 120));
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
        Color c1 = new Color(0, 0, 0);    //a color
        
        g2.setColor(c1);
        g2.fillRect(0, 0, (int)xtotal, (int)ytotal);
        
        //getTime(0, g2);
        getTime(65, g2);
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    
    private void getTime(int time, Graphics2D g2) {
        
        //int display = 150 - getMatchTime();
        int display = 150 - time;
        
        for(int i = 0; i < 3; i++) {
            if(display / 60 == i)
                showNum(0, i, g2);
        }
        
        display = display % 60;
        
        for(int i = 0; i < 6; i++) {
            if(display / 10 == i)
                showNum(1, i, g2);
        }
        
        display = display % 10;
        
        for(int i = 0; i < 10; i++) {
            if(display == i)
                showNum(2, i, g2);
        }
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        double x = 225;
        double y = 120;
        
        Color c1 = new Color(0, 255, 0);
        Color c2 = new Color(0, 0, 0);
        
        int[] xs1 = {(int)(xtotal * (75.0/x)), (int)(xtotal * (80.0/x)), (int)(xtotal * (85.0/x)), (int)(xtotal * (80.0/x))};
        int[] ys1 = {(int)(ytotal * (50.0/y)), (int)(ytotal * (45.0/y)), (int)(ytotal * (50.0/y)), (int)(ytotal * (55.0/y))};
        Polygon dot1 = new Polygon(xs1, ys1, 4);
        
        int[] xs2 = {(int)(xtotal * (75.0/x)), (int)(xtotal * (80.0/x)), (int)(xtotal * (85.0/x)), (int)(xtotal * (80.0/x))};
        int[] ys2 = {(int)(ytotal * (70.0/y)), (int)(ytotal * (65.0/y)), (int)(ytotal * (70.0/y)), (int)(ytotal * (75.0/y))};
        Polygon dot2 = new Polygon(xs2, ys2, 4);
        
        g2.setColor(c1);
        g2.fill(dot1);
        g2.fill(dot2);
        
        g2.setColor(c2);
        g2.draw(dot1);
        g2.draw(dot2);
        
    }
    
    private void showNum(int slot, int number, Graphics2D g2) {
        
        /*tick(15.0, 10.0, false, g2);    // 1
        tick(10.0, 15.0, true, g2);     // 2
        tick(10.0, 60.0, true, g2);     // 3
        tick(15.0, 100.0, false, g2);   // 4
        tick(55.0, 60.0, true, g2);     // 5
        tick(55.0, 15.0, true, g2);     // 6
        tick(15.0, 55.0, false, g2);    // 7
        
        tick(100.0, 10.0, false, g2);   // 1
        tick(95.0, 15.0, true, g2);     // 2
        tick(95.0, 60.0, true, g2);     // 3
        tick(100.0, 100.0, false, g2);  // 4
        tick(140.0, 60.0, true, g2);    // 5
        tick(140.0, 15.0, true, g2);    // 6
        tick(100.0, 55.0, false, g2);   // 7
        
        tick(165.0, 10.0, false, g2);   // 1
        tick(160.0, 15.0, true, g2);    // 2
        tick(160.0, 60.0, true, g2);    // 3
        tick(165.0, 100.0, false, g2);  // 4
        tick(205.0, 60.0, true, g2);    // 5
        tick(205.0, 15.0, true, g2);    // 6
        tick(165.0, 55.0, false, g2);   // 7*/
        
        if(slot == 0) {
            
            if(number == 2) {
                tick(15.0, 10.0, false, g2);    // 1
                tick(10.0, 60.0, true, g2);     // 3
                tick(15.0, 100.0, false, g2);   // 4
                tick(55.0, 15.0, true, g2);     // 6
                tick(15.0, 55.0, false, g2);    // 7
            }
            
            if(number == 1) {
                tick(55.0, 60.0, true, g2);     // 5
                tick(55.0, 15.0, true, g2);     // 6
            }
            
            if(number == 0) {
                tick(15.0, 10.0, false, g2);    // 1
                tick(10.0, 15.0, true, g2);     // 2
                tick(10.0, 60.0, true, g2);     // 3
                tick(15.0, 100.0, false, g2);   // 4
                tick(55.0, 60.0, true, g2);     // 5
                tick(55.0, 15.0, true, g2);     // 6
            }
            
        }
        
        if(slot == 1) {
            
            if(number == 5) {
                tick(100.0, 10.0, false, g2);   // 1
                tick(95.0, 15.0, true, g2);     // 2
                tick(100.0, 100.0, false, g2);  // 4
                tick(140.0, 60.0, true, g2);    // 5
                tick(100.0, 55.0, false, g2);   // 7
            }
            
            if(number == 4) {
                tick(95.0, 15.0, true, g2);     // 2
                tick(140.0, 60.0, true, g2);    // 5
                tick(140.0, 15.0, true, g2);    // 6
                tick(100.0, 55.0, false, g2);   // 7
            }
            
            if(number == 3) {
                tick(100.0, 10.0, false, g2);   // 1
                tick(100.0, 100.0, false, g2);  // 4
                tick(140.0, 60.0, true, g2);    // 5
                tick(140.0, 15.0, true, g2);    // 6
                tick(100.0, 55.0, false, g2);   // 7
            }
            
            if(number == 2) {
                tick(100.0, 10.0, false, g2);   // 1
                tick(95.0, 60.0, true, g2);     // 3
                tick(100.0, 100.0, false, g2);  // 4
                tick(140.0, 15.0, true, g2);    // 6
                tick(100.0, 55.0, false, g2);   // 7
            }
            
            if(number == 1) {
                tick(140.0, 60.0, true, g2);    // 5
                tick(140.0, 15.0, true, g2);    // 6
            }
            
            if(number == 0) {
                tick(100.0, 10.0, false, g2);   // 1
                tick(95.0, 15.0, true, g2);     // 2
                tick(95.0, 60.0, true, g2);     // 3
                tick(100.0, 100.0, false, g2);  // 4
                tick(140.0, 60.0, true, g2);    // 5
                tick(140.0, 15.0, true, g2);    // 6
            }
            
        }
        
        if(slot == 2) {
            
            if(number == 9) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 15.0, true, g2);    // 2
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 8) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 15.0, true, g2);    // 2
                tick(160.0, 60.0, true, g2);    // 3
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 7) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
            }
            
            if(number == 6) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 15.0, true, g2);    // 2
                tick(160.0, 60.0, true, g2);    // 3
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 5) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 15.0, true, g2);    // 2
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 4) {
                tick(160.0, 15.0, true, g2);    // 2
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
            }
            
            if(number == 3) {
                tick(165.0, 10.0, false, g2);   // 1 
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 2) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 60.0, true, g2);    // 3
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 15.0, true, g2);    // 6
                tick(165.0, 55.0, false, g2);   // 7
            }
            
            if(number == 1) {
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
            }
            
            if(number == 0) {
                tick(165.0, 10.0, false, g2);   // 1
                tick(160.0, 15.0, true, g2);    // 2
                tick(160.0, 60.0, true, g2);    // 3
                tick(165.0, 100.0, false, g2);  // 4
                tick(205.0, 60.0, true, g2);    // 5
                tick(205.0, 15.0, true, g2);    // 6
            }
            
        }
        
        
    }
    
    private void tick(double xc, double yc, boolean orient, Graphics2D g2) {
        // true = vertical; false = horizontal
        // 50 * 100 overall number dimension
        
        //double display = 150.0 - getMatchTime();
        
        Color c1 = new Color(0, 255, 0);
        Color c2 = new Color(0, 0, 0);
        
        Dimension size = getSize();
        double xtotal = (int)size.getWidth();
        double ytotal = (int)size.getHeight();
        double x = 225;
        double y = 120;
        
        int[] xs1 = {(int)(xtotal * ((xc + 0.0)/x)), (int)(xtotal * ((xc + 5.0)/x)),
                     (int)(xtotal * ((xc + 10.0)/x)), (int)(xtotal * ((xc + 10.0)/x)),
                     (int)(xtotal * ((xc + 5.0)/x)), (int)(xtotal * ((xc + 0.0)/x))};
        int[] ys1 = {(int)(ytotal * ((yc + 5.0)/y)), (int)(ytotal * ((yc + 0.0)/y)),
                     (int)(ytotal * ((yc + 5.0)/y)), (int)(ytotal * ((yc + 40.0)/y)),
                     (int)(ytotal * ((yc + 45.0)/y)), (int)(ytotal * ((yc + 40.0)/y))};
        Polygon vtick = new Polygon(xs1, ys1, 6);
        
        int[] xs2 = {(int)(xtotal * ((xc + 0.0)/x)), (int)(xtotal * ((xc + 5.0)/x)),
                     (int)(xtotal * ((xc + 40.0)/x)), (int)(xtotal * ((xc + 45.0)/x)),
                     (int)(xtotal * ((xc + 40.0)/x)), (int)(xtotal * ((xc + 5.0)/x))};
        int[] ys2 = {(int)(ytotal * ((yc + 5.0)/y)), (int)(ytotal * ((yc + 0.0)/y)),
                     (int)(ytotal * ((yc + 0.0)/y)), (int)(ytotal * ((yc + 5.0)/y)),
                     (int)(ytotal * ((yc + 10.0)/y)), (int)(ytotal * ((yc + 10.0)/y))};
        Polygon htick = new Polygon(xs2, ys2, 6);
        
        if(orient == true) {
            g2.setColor(c1);
            g2.fill(vtick);
            g2.setColor(c2);
            g2.draw(vtick);
        }
        
        if(orient == false) {
            g2.setColor(c1);
            g2.fill(htick);
            g2.setColor(c2);
            g2.draw(htick);
        }
        
    }
    
}