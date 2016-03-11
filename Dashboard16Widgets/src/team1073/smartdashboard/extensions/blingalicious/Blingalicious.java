/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.blingalicious;

// make sure to IMPORT this stuff before coding stuff
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
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Blingalicious";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Blingalicious");
    
    public Blingalicious() {
        /*This constructor is only necessary for testing purposes*/
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
        
    }
    
}