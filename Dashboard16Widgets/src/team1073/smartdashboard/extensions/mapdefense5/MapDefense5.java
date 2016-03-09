/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.mapdefense5;
// lines 18 and 38 have instructions on what to do for testing the dashboard with the robot

// make sure to IMPORT this stuff before coding stuff
//import static edu.wpi.first.smartdashboard.gui.DashboardFrame.DisplayMode.SmartDashboard;
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import javax.swing.JComboBox;

// "extends Widget" is super-duper important
public class MapDefense5 extends StaticWidget {
    
    //cd C:\Program Files\SmartDashboard
    //java -jar SmartDashboard.jar
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "MapDefense5";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "MapDefense5");

    String[] defenses = {"nothing!", "portcullis", "cheval de fries", "moat", "ramparts", "drawbridge", "sally port", "rock wall", "rough terrain"};
    JComboBox pickDefense = new JComboBox(defenses);
    public int def5;
    
    public MapDefense5() {
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
        pickDefense.setVisible(true);
        this.add(pickDefense);
        setPreferredSize(new Dimension(100, 40));
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
        
        for(int i = 0; i < defenses.length; i++) {
            if(pickDefense.getSelectedItem() == defenses[i]) {
                def5 = i + 1;
            }
        }
        
    }
    
}