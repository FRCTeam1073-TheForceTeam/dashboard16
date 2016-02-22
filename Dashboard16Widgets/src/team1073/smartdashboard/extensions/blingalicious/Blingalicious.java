/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.blingalicious;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import javax.swing.JButton;
import javax.swing.JSlider;

//"extends Widget" is super-duper important
public class Blingalicious extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Blingalicious";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Blingalicious");

    
    public Blingalicious() {
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
        JSlider brightness = new JSlider();
        brightness.setVisible(true);
        this.add(brightness);
        
        int percent = brightness.getValue();
        // send to bling
        
        JButton explode = new JButton("Explode!");
        //explode.setBounds(0, 40, 20, 20);
        explode.setVisible(true);
        this.add(explode);
        
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
    private void drawStuff(Graphics2D g2) {
        
        Dimension size = getSize();
        double xtotal = size.getWidth();
        double ytotal = size.getHeight();
        
    }
    
}