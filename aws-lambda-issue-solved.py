import boto3

# Replace these with your AWS credentials and region
aws_access_key = 'YOUR_ACCESS_KEY'
aws_secret_key = 'YOUR_SECRET_KEY'
aws_region = 'us-east-1'

# Initialize the Boto3 AWS Lambda client
lambda_client = boto3.client('lambda', aws_access_key_id=aws_access_key, aws_secret_access_key=aws_secret_key, region_name=aws_region)

# Define the Lambda function properties
function_name = 'MyLambdaFunction'
runtime = 'python3.8'
handler = 'my_lambda_function.handler'  # Replace with your actual handler function
role_arn = 'arn:aws:iam::YOUR_ACCOUNT_ID:role/MyLambdaRole'  # Replace with your actual IAM role ARN
function_file = 'my_lambda_function.py'  # Replace with the actual path to your Python file

# Read the Python code from the file
with open(function_file, 'r') as file:
    function_code = file.read()

# Create the Lambda function
lambda_client.create_function(
    FunctionName=function_name,
    Runtime=runtime,
    Role=role_arn,
    Handler=handler,
    Code={
        'ZipFile': function_code.encode('utf-8')
    },
    Timeout=15,  # Adjust the timeout as needed
    MemorySize=128  # Adjust the memory size as needed
)

print(f'Lambda function "{function_name}" created successfully.')
