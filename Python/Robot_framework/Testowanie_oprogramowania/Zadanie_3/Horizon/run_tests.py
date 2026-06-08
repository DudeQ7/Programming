import robot
import os
current_dir = os.path.dirname(os.path.abspath(__file__))
robot_file = os.path.join(current_dir, "zadanie3_horizon.robot")
output_path = os.path.join(current_dir, "results")
img_path = os.path.join(current_dir, "images")

if __name__ == "__main__":
    if not os.path.exists(output_path):
        os.makedirs(output_path)
    robot.run(robot_file, outputdir=output_path, variable=[f"IMAGE_PATH:{img_path}"])
