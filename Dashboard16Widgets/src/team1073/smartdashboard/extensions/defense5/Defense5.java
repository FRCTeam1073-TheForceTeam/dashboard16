/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.defense5;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;

//"extends Widget" is super-duper important
public class Defense5 extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Defense5";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Defense 5");

    
    public Defense5() {
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
        int xTotal = (int)size.getWidth();
        int yTotal = (int)size.getHeight();
        //establish default colors
        
        //drawLowBar(g2);
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    
    private void drawLowBar(Graphics2D g2) {
        
        int x = 200;
        int y = 80;
        
        Dimension size = getSize();
        int xtotal = (int)size.getWidth();
        int ytotal = (int)size.getHeight();
        
        Color c1 = new Color(0, 0, 0);  // platform fill
        Color c2 = new Color(0, 0, 0);  // platform outline
        // 50" * 3"
        Rectangle platform = new Rectangle(0, ytotal * (68/y), xtotal * (200/x), ytotal * (12/y));
        //Rectangle platform = new Rectangle(0, 68, (int) xtotal * (200/200), 12);
        //Rectangle platform = new Rectangle(0, 0, (int) xtotal, (int) ytotal);

        g2.setColor(c2);
        g2.fill(platform);
        g2.setColor(c1);
        g2.draw(platform);
        
    }
    
}