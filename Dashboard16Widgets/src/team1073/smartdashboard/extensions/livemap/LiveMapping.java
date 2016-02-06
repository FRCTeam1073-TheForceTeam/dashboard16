/*
 * **HEADER**
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

//"extends Widget" is super-duper important
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
        double xTotal = size.getWidth();
        double yTotal = size.getHeight();
        //establish default colors
        
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    
    public void drawMap(Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        // 1 pixel = 1"
        double x = 319; // 26' 7"
        double y = 649; // 54' 1"
        
        Rectangle field = new Rectangle(0, 0, (int)xtotal, (int)ytotal);
        
    }
    
}