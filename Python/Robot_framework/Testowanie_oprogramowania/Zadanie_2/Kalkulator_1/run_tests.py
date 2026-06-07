import robot 
import os
current_dir = os.path.dirname(os.path.abspath(__file__))
robot_file = os.path.join(current_dir, "calculator_win32calc.robot")
output_path = os.path.join(current_dir, "results")
if __name__ == "__main__":
    robot.run(robot_file, outputdir=output_path)