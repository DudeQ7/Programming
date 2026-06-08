import os
import subprocess
import sys

def run_robot_tests():
    # Define paths
    project_dir = os.path.dirname(os.path.abspath(__file__))
    robot_file = os.path.join(project_dir, "zadanie3_horizon.robot")
    output_dir = os.path.join(project_dir, "results")
    
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # Robot Framework command
    # Assuming robot is installed in the environment
    command = [
        "robot",
        "--outputdir", output_dir,
        "--name", "Horizon_Calculator_Tests",
        robot_file
    ]
    
    print(f"Running command: {' '.join(command)}")
    
    try:
        # Run the tests
        result = subprocess.run(command, check=False)
        sys.exit(result.returncode)
    except FileNotFoundError:
        print("Error: 'robot' command not found. Please ensure Robot Framework is installed.")
        sys.exit(1)

if __name__ == "__main__":
    run_robot_tests()
