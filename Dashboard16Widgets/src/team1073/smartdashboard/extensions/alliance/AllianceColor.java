/*
 * **HEADER**
 */
package team1073.smartdashboard.extensions.alliance;


// make sure to IMPORT this stuff before coding stuff
import edu.wpi.first.smartdashboard.gui.StaticWidget;
import edu.wpi.first.smartdashboard.gui.Widget;
import edu.wpi.first.smartdashboard.properties.MultiProperty;
import edu.wpi.first.smartdashboard.properties.Property;
import edu.wpi.first.smartdashboard.types.DataType;
import java.awt.*;
import javax.swing.JComboBox;

//"extends Widget" is super-duper important
public class AllianceColor extends StaticWidget {
    
    public static final DataType[] TYPES = {DataType.NUMBER};
    public static final String NAME = "Alliance";
    private int value = -1;
    public final MultiProperty mode = new MultiProperty(this, "Alliance Color");
    
    public static String allianceTeam;
    public static String opposingTeam;
    
    String[] allianceOptions = {"nothing", "blue", "red"};
    JComboBox pickTeam = new JComboBox(allianceOptions);

    
    public AllianceColor() {
        /*This constructor is only necessary for testing purposes*/
    }
    
    ////////////@Override
    public void setValue(Object o) {
        this.value = ((Number) o).intValue();
        repaint();
    }

    @Override
    public void init() {
        setPreferredSize(new Dimension(100, 30));
        pickTeam.setVisible(true);
        this.add(pickTeam);
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
        
        if(pickTeam.getSelectedItem() == "blue") {
            allianceTeam = "blue";
            opposingTeam = "red";
        }
        
        else if(pickTeam.getSelectedItem() == "red") {
            allianceTeam = "red";
            opposingTeam = "blue";
        }
        
        else {
            allianceTeam = "";
            opposingTeam = "";
        }
        
    }
    
}