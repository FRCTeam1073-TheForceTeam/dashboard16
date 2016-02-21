/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dashboard16widgets;
/**
 *
 * @author Julia
 */
import edu.wpi.first.smartdashboard.robot.Robot;
import edu.wpi.first.wpilibj.networktables.NetworkTable;
import edu.wpi.first.wpilibj.tables.ITable;

public class Dashboard16Widgets {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        ITable table = Robot.getTable();
        //table.beginTransaction();
        
        int xcRobot = (int)(table.getNumber("xcRobot", 100));
        int ycRobot = (int)(table.getNumber("ycRobot", 100));
        
        double lauchElev = table.getNumber("lauchElev", 45.0);
        double defManip = table.getNumber("defManip", 45.0);
        boolean piston = table.getBoolean("piston", true);
        
        
        
        //table.endTransaction();
        
    }
    
}

