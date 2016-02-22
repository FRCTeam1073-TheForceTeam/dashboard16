/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.autodefense;


// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.DashboardFrame;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.gui.elements.Chooser;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import java.awt.*;
import javafx.scene.control.ComboBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;

//"extends Widget" is super-duper important
public class AutoDefense extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "AutoDefense";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Pick Defense");

    
    public AutoDefense() {
        /*This constructor is only necessary for testing purposes*/
        //sets different options for different stuff on the dashboard
        
        mode.add("nothing!", 0);
        
    }
    
    ////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        
        setPreferredSize(new Dimension(100, 30));
        String[] defenses = {"1", "2", "3", "4", "5"};
        JComboBox pickDefense = new JComboBox(defenses);
        //pickDefense.setBounds(new Rectangle(0, 0, 100, 40));
        pickDefense.setVisible(true);
        this.add(pickDefense);
        
        if(pickDefense.getSelectedItem() == "1") {
            //Robot.put();
        }
        
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
        
        
        
        /*if(pickDefense.getSelectedItem() == "1") {
            // do this
        }*/
        
        if(value == 0) {
            //mode.add("nothing!", 0);
        }
        
    }
    
}