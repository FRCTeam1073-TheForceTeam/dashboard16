/*
 * **HEADER**

 * "todo" extends Widget & uncomment out override (line 43)

 */
package team1073.smartdashboard.extensions.livemap;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import java.util.Random;

//"extends Widget" is super-duper important
// google todo
// change to "extends Widget" to test with Robot
public class LiveMapping extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "LiveMapping";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Live Map");

    
    public LiveMapping() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        
    }
    
    
    // uncomment out this override
    ////////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        // just fits vertically...
        setPreferredSize(new Dimension(319, 649));
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
        
        drawMap(g2);
        
        // int[267][541]
        //int[][] fieldArray = getMapArray();
        int[][] fieldArray = new int[267][541];
        
        /*drawPlatform(0.0, 192.0, g2);
        drawPlatform(50.0, 192.0, g2);
        drawPlatform(100.0, 192.0, g2);
        drawPlatform(150.0, 192.0, g2);
        drawPlatform(200.0, 192.0, g2);*/
        Random rand = new Random(9);
        int[] defenseXArray = new int[10];
        int[] defenseYArray = new int[10];
        
        /*for(int i = 0; i < 10; i++) {
            defenseXArray[i] = rand.nextInt() + 1;
            defenseYArray[i] = rand.nextInt() + 1;
        }*/
        
        int[] defenses = new int[10];
        
        
        
        double dx = 0.0;
        for(int i = 0; i < 5; i++) {
            //inputDefense(fieldArray[defenseXArray[i]][defenseYArray[i]], dx, 192.0, g2);
            inputDefense(rand.nextInt() + 1, dx, 192.0, g2);
            dx+=50;
        }
        
        /*drawPlatform(54.0, 410.0, g2);
        drawPlatform(104.0, 410.0, g2);
        drawPlatform(154.0, 410.0, g2);
        drawPlatform(204.0, 410.0, g2);
        drawPlatform(254.0, 410.0, g2);*/
        
        dx = 69.0;
        for(int i = 5; i < 10; i++) {
            //inputDefense(fieldArray[defenseXArray[i]][defenseYArray[i]], dx, 410.0, g2);
            inputDefense(rand.nextInt() + 1, dx, 410.0, g2);
            dx+=50;
        }
        
        // get array
        double xc = 108.0;
        double yc = 471.0;
        
        // get field array (rename - do not change for loop)
        
        
        for(int i = 0; i < fieldArray.length; i++) {
            for(int j = 0; j < fieldArray[i].length; j++) {
                fieldArray[i][j] = 0;
            }
        }
        
        fieldArray[50][200] = 1;
        
        for(double i = 0.0; i < fieldArray[0].length; i++) {
            for(double j = 0.0; j < fieldArray.length; j++) {
                if(fieldArray[(int)j][(int)i] == 1) {
                    xc = xtotal * (j / fieldArray.length);
                    yc = ytotal * (i / fieldArray[0].length);
                }
            }
        }
        
        drawRobot(xc, yc, g2);
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    
    private void drawPlatform(double dx, double dy, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        // 1 pixel = 1"
        double x = 319; // 26' 7"
        double y = 649; // 54' 1"
        
        Color c1 = new Color(204, 204, 204);    // steel gray
        Color c2 = new Color(95, 95, 91);       // outline
        
        //Rectangle platform1 = new Rectangle((int)(xtotal * ((dx + 0.0)/x)), (int)(ytotal * ((dy + 0.0)/y)), (int)(xtotal * ((dx + 0.0)/x)), (int)(ytotal * ((dy + 0.0)/y)));
        Rectangle platform = new Rectangle((int)(xtotal * ((dx + 0.0)/x)), (int)(ytotal * ((dy + 12.0)/y)), (int)(xtotal * (50.0/x)), (int)(ytotal * (24.0/y)));
        Rectangle ramp1 = new Rectangle((int)(xtotal * ((dx + 0.0)/x)), (int)(ytotal * ((dy + 0.0)/y)), (int)(xtotal * (50.0/x)), (int)(ytotal * (12.0/y)));
        Rectangle ramp2 = new Rectangle((int)(xtotal * ((dx + 0.0)/x)), (int)(ytotal * ((dy + 36.0)/y)), (int)(xtotal * (50.0/x)), (int)(ytotal * (12./y)));

        g2.setColor(c1);
        g2.fill(platform);
        g2.fill(ramp1);
        g2.fill(ramp2);
        
        g2.setColor(c2);
        g2.draw(platform);
        g2.draw(ramp1);
        g2.draw(ramp2);
        
    }
    
    public void inputDefense(int defense, double xc, double yc, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        // 1 pixel = 1"
        double x = 319; // 26' 7"
        double y = 649; // 54' 1"
        
        if(defense == 1) {
            g2.setColor(new Color(255, 0, 0));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * (50.0/x)), (int)(ytotal * (24.0/y)));
        }
        
        if(defense == 2) {
            g2.setColor(new Color(255, 255, 0));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * (50.0/x)), (int)(ytotal * (24.0/y)));
        }
        
        if(defense == 3) {
            g2.setColor(new Color(255, 0, 255));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 4) {
            g2.setColor(new Color(255, 0, 0));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 5) {
            g2.setColor(new Color(255, 255, 255));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 6) {
            g2.setColor(new Color(255, 0, 255));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 7) {
            g2.setColor(new Color(100, 0, 255));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 8) {
            g2.setColor(new Color(0, 0, 255));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
        if(defense == 9) {
            g2.setColor(new Color(0, 0, 0));
            g2.fillRect((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * ((xc + 50.0)/x)), (int)(ytotal * ((yc + 24.0)/y)));
        }
        
    }
    
    private void drawRobot(double xc, double yc, Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        // 1 pixel = 1"
        double x = 319; // 26' 7"
        double y = 649; // 54' 1"
        // int[267][541]
        
        Color c1 = new Color(0, 0, 0);
        Color c2 = new Color(0, 0, 0);
        
        Rectangle robot = new Rectangle((int)(xtotal * (xc/x)), (int)(ytotal * (yc/y)), (int)(xtotal * (32/x)), (int)(ytotal * (32/y)));
        
        g2.setColor(c1);
        g2.fill(robot);
        
        g2.setColor(c2);
        g2.draw(robot);
        
    }
    
    public void drawMap(Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        // 1 pixel = 1"
        double x = 319; // 26' 7"
        double y = 649; // 54' 1"
        // int[267][541]
        
        Color c1 = new Color(47, 76, 55);       // scotch pine
        Color c2 = new Color(204, 204, 204);    // steel gray
        Color c3 = new Color(47, 67, 55);       // green lines
        Color c4 = new Color(223, 41, 43);      // sp red
        Color c5 = new Color(16, 87, 239);      // sp blue
        Color c6 = new Color(95, 95, 91);       // steel outline
        Color c7 = new Color(1, 1, 1);          // castle top
        Color c8 = new Color(129, 135, 142);    // batter lines
        
        Rectangle field = new Rectangle(0, 0, (int)xtotal, (int)ytotal);
        Rectangle midline = new Rectangle(0, (int)(ytotal * (320.0/y)), (int)(xtotal * (319.0/x)), (int)(ytotal * (8.0/y)));
        Rectangle centerline = new Rectangle((int)(xtotal * (159.0/x)), 0, (int)(xtotal * (4.0/x)), (int)(ytotal * (649.0/y)));
        
        // 24' * 4' 6"
        Rectangle secretpassage1 = new Rectangle((int)(xtotal * (250.0/x)), 0, (int)(xtotal * (69.0/x)), (int)(ytotal * (288.0/y))); // red
        Rectangle secretpassage2 = new Rectangle(0, (int)(ytotal * (361.0/y)), (int)(xtotal * (69.0/x)), (int)(ytotal * (288.0/y))); // blue
        
        int[] xs1 = {(int)(xtotal * (106.0/x)), (int)(xtotal * (106.0/x)),
                     (int)(xtotal * (118.0/x)), (int)(xtotal * (160.0/x)),
                     (int)(xtotal * (184.0/x)), (int)(xtotal * (226.0/x)),
                     (int)(xtotal * (238.0/x)), (int)(xtotal * (238.0/x))};
        int[] ys1 = {(int)(ytotal * (0.0/y)), (int)(ytotal * (24.0/y)),
                     (int)(ytotal * (45.0/y)), (int)(ytotal * (69.0/y)),
                     (int)(ytotal * (69.0/y)), (int)(ytotal * (45.0/y)),
                     (int)(ytotal * (24.0/y)), (int)(ytotal * (0.0/y))};
        Polygon castle1 = new Polygon(xs1, ys1, 8);
        
        int[] xs2 = {(int)(xtotal * (81.0/x)), (int)(xtotal * (81.0/x)),
                     (int)(xtotal * (93.0/x)), (int)(xtotal * (135.0/x)),
                     (int)(xtotal * (159.0/x)), (int)(xtotal * (201.0/x)),
                     (int)(xtotal * (213.0/x)), (int)(xtotal * (213.0/x))};
        int[] ys2 = {(int)(ytotal * (649.0/y)), (int)(ytotal * (625.0/y)),
                     (int)(ytotal * (604.0/y)), (int)(ytotal * (580.0/y)),
                     (int)(ytotal * (580.0/y)), (int)(ytotal * (604.0/y)),
                     (int)(ytotal * (625.0/y)), (int)(ytotal * (649.0/y))};
        Polygon castle2 = new Polygon(xs2, ys2, 8);
        
        int[] xs3 = {(int)(xtotal * (148.0/x)), (int)(xtotal * (160.0/x)), (int)(xtotal * (184.0/x)), (int)(xtotal * (196.0/x))};
        int[] ys3 = {(int)(ytotal * (0.0/y)), (int)(ytotal * (21.0/y)), (int)(ytotal * (21.0/y)), (int)(ytotal * (0.0/y))};
        Polygon castle1top = new Polygon(xs3, ys3, 4);
        
        int[] xs4 = {(int)(xtotal * (123.0/x)), (int)(xtotal * (135.0/x)), (int)(xtotal * (159.0/x)), (int)(xtotal * (171.0/x))};
        int[] ys4 = {(int)(ytotal * (649.0/y)), (int)(ytotal * (628.0/y)), (int)(ytotal * (628.0/y)), (int)(ytotal * (649.0/y))};
        Polygon castle2top = new Polygon(xs4, ys4, 4);
        
        g2.setColor(c1);
        g2.fill(field);
        
        g2.setColor(c3);
        g2.fill(centerline);
        
        g2.setColor(c2);
        g2.fill(midline);
        g2.fill(castle1);
        g2.fill(castle2);
        
        g2.setColor(c4);
        g2.draw(secretpassage1);
        
        g2.setColor(c5);
        g2.draw(secretpassage2);
        
        drawPlatform(0.0, 192.0, g2);
        drawPlatform(50.0, 192.0, g2);
        drawPlatform(100.0, 192.0, g2);
        drawPlatform(150.0, 192.0, g2);
        drawPlatform(200.0, 192.0, g2);
        
        drawPlatform(69.0, 410.0, g2);
        drawPlatform(119.0, 410.0, g2);
        drawPlatform(169.0, 410.0, g2);
        drawPlatform(219.0, 410.0, g2);
        drawPlatform(269.0, 410.0, g2);
        
        g2.setColor(c6);
        g2.draw(castle1);
        g2.draw(castle2);
        
        g2.setColor(c7);
        g2.fill(castle1top);
        g2.fill(castle2top);
        
        g2.setColor(c8);
        
        g2.drawLine((int)(xtotal * (106.0/x)), (int)(ytotal * (24.0/y)), (int)(xtotal * (148.0/x)), 0);
        g2.drawLine((int)(xtotal * (118.0/x)), (int)(ytotal * (45.0/y)), (int)(xtotal * (160.0/x)), (int)(ytotal * (21.0/y)));
        g2.drawLine((int)(xtotal * (160.0/x)), (int)(ytotal * (69.0/y)), (int)(xtotal * (160.0/x)), (int)(ytotal * (21.0/y)));
        g2.drawLine((int)(xtotal * (184.0/x)), (int)(ytotal * (69.0/y)), (int)(xtotal * (184.0/x)), (int)(ytotal * (21.0/y)));
        g2.drawLine((int)(xtotal * (184.0/x)), (int)(ytotal * (21.0/y)), (int)(xtotal * (226.0/x)), (int)(ytotal * (45.0/y)));
        g2.drawLine((int)(xtotal * (196.0/x)), 0, (int)(xtotal * (238.0/x)), (int)(ytotal * (24.0/y)));
        g2.draw(castle1top);
        
        //g2.drawLine((int)(xtotal * (0.0/x)), (int)(ytotal * (0.0/y)), (int)(xtotal * (0.0/x)), (int)(ytotal * (0.0/y)));
        g2.drawLine((int)(xtotal * (81.0/x)), (int)(ytotal * (625.0/y)), (int)(xtotal * (123.0/x)), (int)(ytotal * (649.0/y)));
        g2.drawLine((int)(xtotal * (93.0/x)), (int)(ytotal * (604.0/y)), (int)(xtotal * (135.0/x)), (int)(ytotal * (628.0/y)));
        g2.drawLine((int)(xtotal * (135.0/x)), (int)(ytotal * (580.0/y)), (int)(xtotal * (135.0/x)), (int)(ytotal * (628.0/y)));
        g2.drawLine((int)(xtotal * (159.0/x)), (int)(ytotal * (580.0/y)), (int)(xtotal * (159.0/x)), (int)(ytotal * (628.0/y)));
        g2.drawLine((int)(xtotal * (201.0/x)), (int)(ytotal * (604.0/y)), (int)(xtotal * (159.0/x)), (int)(ytotal * (628.0/y)));
        g2.drawLine((int)(xtotal * (213.0/x)), (int)(ytotal * (625.0/y)), (int)(xtotal * (171.0/x)), (int)(ytotal * (649.0/y)));
        g2.draw(castle2top);
        
    }
    
}