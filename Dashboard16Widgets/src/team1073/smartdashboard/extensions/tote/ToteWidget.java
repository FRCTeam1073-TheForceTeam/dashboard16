/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.tote;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.RenderingHints;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;

//"extends Widget" is super-duper important
public class ToteWidget extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Tote";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Tote");

    
    public ToteWidget() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        mode.add("1 tote", 1);
        mode.add("2 totes", 2);
        mode.add("3 totes", 3);
        mode.add("4 totes", 4);
        mode.add("container", 5);
        mode.add("1 tote w/ container", 6);
        mode.add("2 totes w/ container", 7);
        mode.add("3 totes w/ container", 8);
        mode.add("4 totes w/ container", 9);
    }
    
    ////////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        setPreferredSize(new Dimension(300, 600));
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
        Color c1 = new Color(159, 159, 159);    //toteColorGray
        Color c2 = new Color(141, 141, 141);    //toteGrayOutline
        Color c3 = new Color(232, 236, 51);     //toteYellow
        Color c4 = new Color(243, 177, 24);     //toteTellowOutline
        Color c5 = new Color(25, 113, 45);      //containerColor = dark green
        Color c6 = new Color(18, 80, 32);       //containerOutline
        Color c7 = new Color(177, 227, 26);     //noodle!
        Color c8 = new Color(155, 199, 22);     //noodle!Outline
        
        /*
        // testing
        g2.setPaint(c8);
        //g2.drawArc(in x, int y, int width, int height, int startAngle, int arcAngle);
        g2.drawArc(50, 50, 100, 100, 120, 120);
        */
        
        //establish default shapes and draw individually
        //after establisdhing default shape, must g2.draw(it);
        //Rectangle2D.Double box = new Rectangle2D.Double(110, 480, 180, 100);
        
            /*
            //totes(copy&paste)
            
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1/c3, c2/c4, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c1/c3, c2/c4, g2);
            //tote 3
            drawTote((int)(yTotal * (338.0/600.0)), c1/c3, c2/c4, g2);
            //tote 4
            drawTote((int)(yTotal * (257.0/600.0)), c1, c2, g2);
        
            //containers(copy&paste)
            
            //container(ground)
            drawContainer((int)(yTotal * (388.0/600.0)), c5, c6, g2);
            //container(on 1 tote)
            drawContainer((int)(yTotal * (307.0/600.0)), c5, c6, g2);
            //container(on 2 totes)
            drawContainer((int)(yTotal * (226.0/600.0)), c5, c6, g2);
            //container(on 3 totes)
            drawContainer((int)(yTotal * (145.0/600.0)), c5, c6, g2);
            //container(on 4 totes)
            drawContainer((int)(yTotal * (64.0/600.0)), c5, c6, g2);
            */
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
        if(value == 1) {
            //mode.add("1 tote", 1);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
        }
        
        if(value == 2) {
            //mode.add("2 totes", 2);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c3, c4, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c1, c2, g2);
        }
            
        if(value == 3) {
            //mode.add("3 totes", 3);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c3, c4, g2);
            //tote 3
            drawTote((int)(yTotal * (338.0/600.0)), c1, c2, g2);
        }
        
        if(value == 4) {
            //mode.add("4 totes", 4);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c1, c2, g2);
            //tote 3
            drawTote((int)(yTotal * (338.0/600.0)), c3, c4, g2);
            //tote 4
            drawTote((int)(yTotal * (257.0/600.0)), c1, c2, g2);
        }
        
        if(value == 5) {
            //mode.add("container", 5);
            //container(ground)
            drawContainer((int)(yTotal * (388.0/600.0)), c5, c6, g2);
        }
        
        if(value == 6) {
            //mode.add("1 tote w/ container", 6);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
            //container(on 1 tote)
            drawContainer((int)(yTotal * (307.0/600.0)), c5, c6, g2);
        }
        
        if(value == 7) {
            //mode.add("2 totes w/ container", 7);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c3, c4, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c1, c2, g2);
            //container(on 2 totes)
            drawContainer((int)(yTotal * (226.0/600.0)), c5, c6, g2);
        }
        
        if(value == 8) {
            //mode.add("3 totes w/ container", 8);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c3, c4, g2);
            //tote 3
            drawTote((int)(yTotal * (338.0/600.0)), c1, c2, g2);
            //container(on 3 totes)
            drawContainer((int)(yTotal * (145.0/600.0)), c5, c6, g2);
        }
        
        if(value == 9) {
            //mode.add("4 totes w/ container", 9);
            //tote 1
            drawTote((int)(yTotal * (500.0/600.0)), c1, c2, g2);
            //tote 2
            drawTote((int)(yTotal * (419.0/600.0)), c1, c2, g2);
            //tote 3
            drawTote((int)(yTotal * (338.0/600.0)), c3, c4, g2);
            //tote 4
            drawTote((int)(yTotal * (257.0/600.0)), c1, c2, g2);
            //container(on 4 totes)
            drawContainer((int)(yTotal * (64.0/600.0)), c5, c6, g2);
        }
        
    }
    private void drawTote(int y, Color c1, Color c2, Graphics2D g2){
        
        Dimension size = getSize();
        double xTotal = (int)size.getWidth();
        double yTotal = (int)size.getHeight();
        //toteBase
        int[] xs1 = new int[4];
        int[] ys1 = new int[4];
        xs1[0] = (int)(xTotal * (64.0/300.0));
        xs1[1] = (int)(xTotal * (67.0/300.0));
        xs1[2] = (int)(xTotal * (233.0/300.0));
        xs1[3] = (int)(xTotal * (236.0/300.0));
        ys1[0] = y + (int)(yTotal * (10.0/600.0));
        ys1[1] = y + (int)(yTotal * (80.0/600.0));
        ys1[2] = y + (int)(yTotal * (80.0/600.0));
        ys1[3] = y + (int)(yTotal * (10.0/600.0));
        Polygon toteBase = new Polygon(xs1, ys1, 4);
        
        g2.setPaint(c1);
        
        g2.fillRect((int)(xTotal * (62.0/300.0)), y, (int)(xTotal * (176.0/300.0)), (int)(yTotal * (10.0/600.0)));
        g2.fillPolygon(toteBase);
        g2.fillRect((int)(xTotal * (62.0/300.0)), y, (int)(xTotal * (10.0/300.0)), (int)(yTotal * (25.0/600.0)));
        g2.fillRect((int)(xTotal * (229.0/300.0)), y, (int)(xTotal * (10.0/300.0)), (int)(yTotal * (25.0/600.0)));
        
        g2.setPaint(c2);
        
        g2.drawRect((int)(xTotal * (62.0/300.0)), y, (int)(xTotal * (176.0/300.0)), (int)(yTotal * 10.0/600.0));
        g2.drawPolygon(toteBase);
        g2.drawLine((int)(xTotal * (73.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (76.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (95.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (92.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (106.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (109.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (109.0/300.0)), y + (int)(yTotal * (60.0/600.0)), (int)(xTotal * (125.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (128.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (125.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (139.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (142.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (161.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (158.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (172.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (175.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (175.0/300.0)), y + (int)(yTotal * (60.0/600.0)), (int)(xTotal * (191.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (194.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (191.0/300.0)), y + (int)(yTotal * (60.0/600.0)));
        g2.drawLine((int)(xTotal * (205.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (208.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (227.0/300.0)), y + (int)(yTotal * (10.0/600.0)), (int)(xTotal * (224.0/300.0)), y + (int)(yTotal * (80.0/600.0)));
        g2.drawLine((int)(xTotal * (62.0/300.0)), y, (int)(xTotal * (62.0/300.0)), y + (int)(yTotal * (25.0/600.0)));
        g2.drawLine((int)(xTotal * (62.0/300.0)), y + (int)(yTotal * (25.0/600.0)), (int)(xTotal * (65.0/300.0)), y + (int)(yTotal * (25.0/600.0)));
        g2.drawLine((int)(xTotal * (238.0/300.0)), y, (int)(xTotal * (238.0/300.0)), y + (int)(yTotal * (25.0/600.0)));
        g2.drawLine((int)(xTotal * (238.0/300.0)), y + (int)(yTotal * (25.0/600.0)), (int)(xTotal * (235.0/300.0)), y + (int)(yTotal * 25.0/600.0));
    
    }
    /*
    private void drawNoodle(int y, Color c1, Color c2, Graphics2D g2) {
        
        Dimension size = getSize();
        double xTotal = (int)size.getWidth();
        double yTotal = (int)size.getHeight();
        
        int[] xs1 = new int[4];
        int[] ys1 = new int[4];
        
        
    }
    */
    private void drawContainer(int y, Color c1, Color c2, Graphics2D g2) {
        
        Dimension size = getSize();
        double xTotal = (int)size.getWidth();
        double yTotal = (int)size.getHeight();
        
        //containerTop
        int[] xs1 = new int[4];
        int[] ys1 = new int[4];
        xs1[0] = (int)(xTotal * (77.0/300.0));
        xs1[1] = (int)(xTotal * (85.0/300.0));
        xs1[2] = (int)(xTotal * (215.0/300.0));
        xs1[3] = (int)(xTotal * (223.0/300.0));
        ys1[0] = y + (int)(yTotal * (8.0/600.0));
        ys1[1] = y;
        ys1[2] = y;
        ys1[3] = y + (int)(yTotal * (8.0/600.0));
        Polygon containerTop = new Polygon(xs1, ys1, 4);
        
        //containerBase
        int[] xs2 = new int[4];
        int[] ys2 = new int[4];
        xs2[0] = (int)(xTotal * (82.0/300.0));
        xs2[1] = (int)(xTotal * (90.0/300.0));
        xs2[2] = (int)(xTotal * (211.0/300.0));
        xs2[3] = (int)(xTotal * (218.0/300.0));
        ys2[0] = y + (int)(yTotal * (52.0/600.0));
        ys2[1] = y + (int)(yTotal * (192.0/600.0));
        ys2[2] = y + (int)(yTotal * (192.0/600.0));
        ys2[3] = y + (int)(yTotal * (52.0/600.0));
        Polygon containerBase = new Polygon(xs2, ys2, 4);
        
        //containerHandleLeft
        int[] xs3 = new int[6];
        int[] ys3 = new int[6];
        xs3[0] = (int)(xTotal * (72.0/300.0));
        xs3[1] = (int)(xTotal * (64.0/300.0));
        xs3[2] = (int)(xTotal * (60.0/300.0));
        xs3[3] = (int)(xTotal * (60.0/300.0));
        xs3[4] = (int)(xTotal * (78.0/300.0));
        xs3[5] = (int)(xTotal * (78.0/300.0));
        ys3[0] = y + (int)(yTotal * (16.0/600.0));
        ys3[1] = y + (int)(yTotal * (36.0/600.0));
        ys3[2] = y + (int)(yTotal * (36.0/600.0));
        ys3[3] = y + (int)(yTotal * (44.0/600.0));
        ys3[4] = y + (int)(yTotal * (52.0/600.0));
        ys3[5] = y + (int)(yTotal * (16.0/600.0));
        Polygon containerHandleLeft = new Polygon(xs3, ys3, 6);
        
        //containerHandleRight
        int[] xs4 = new int[6];
        int[] ys4 = new int[6];
        xs4[0] = (int)(xTotal * (228.0/300.0));
        xs4[1] = (int)(xTotal * (236.0/300.0));
        xs4[2] = (int)(xTotal * (240.0/300.0));
        xs4[3] = (int)(xTotal * (240.0/300.0));
        xs4[4] = (int)(xTotal * (222.0/300.0));
        xs4[5] = (int)(xTotal * (222.0/300.0));       
        ys4[0] = y + (int)(yTotal * (16.0/600.0));
        ys4[1] = y + (int)(yTotal * (36.0/600.0));
        ys4[2] = y + (int)(yTotal * (36.0/600.0));
        ys4[3] = y + (int)(yTotal * (44.0/600.0));
        ys4[4] = y + (int)(yTotal * (52.0/600.0));
        ys4[5] = y + (int)(yTotal * (16.0/600.0));
        Polygon containerHandleRight = new Polygon(xs4, ys4, 6);

        
        g2.setPaint(c1);
        
        g2.fillRect((int)(xTotal * (72.0/300.0)), y + (int)(yTotal * (8.0/600.0)), (int)(xTotal * (156.0/300.0)), (int)(yTotal * (4.0/600.0)));
        g2.fillRect((int)(xTotal * (66.0/300.0)), y + (int)(yTotal * (12.0/600.0)), (int)(xTotal * (168.0/300.0)), (int)(yTotal * (4.0/600.0)));
        g2.fillRect((int)(xTotal * (78.0/300.0)), y + (int)(yTotal * (16.0/600.0)), (int)(xTotal * (144.0/300.0)), (int)(yTotal * (36.0/600.0)));
        g2.fill(containerTop);
        g2.fill(containerBase);
        g2.fill(containerHandleLeft);
        g2.fill(containerHandleRight);
        
        g2.setPaint(c2);
        
        g2.drawRect((int)(xTotal * (78.0/300.0)), y + (int)(yTotal * (16.0/600.0)), (int)(xTotal * (144.0/300.0)), (int)(yTotal * (36.0/600.0)));
        g2.drawRect((int)(xTotal * (72.0/300.0)), y + (int)(yTotal * (8.0/600.0)), (int)(xTotal * (156.0/300.0)), (int)(yTotal * (4.0/600.0)));
        g2.drawRect((int)(xTotal * (66.0/300.0)), y + (int)(yTotal * (12.0/600.0)), (int)(xTotal * (168.0/300.0)), (int)(yTotal * (4.0/600.0)));
        g2.draw(containerTop);
        g2.draw(containerHandleLeft);
        g2.draw(containerHandleRight);
        g2.draw(containerBase);
        
    }
    
}