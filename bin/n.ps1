param (
    [string]$filename
)

# Get the directory of the script
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path

# Define the template file path (in the script's directory)
$templateFile = Join-Path $scriptDir "template.cpp"

# Define the target file path (in the current working directory)
$targetFile = Join-Path (Get-Location) "$filename.cpp"

# Check if the template file exists
if (-Not (Test-Path $templateFile)) {
    Write-Host "Error: template.cpp not found in $scriptDir" -ForegroundColor Red
    exit 1
}

# Check if the target file already exists
if (Test-Path $targetFile) {
    Write-Host "Error: The file '$filename.cpp' already exists in $(Get-Location)." -ForegroundColor Yellow
    exit 1
}

# Copy the template content to the new file in the current directory
Copy-Item -Path $templateFile -Destination $targetFile

Write-Host "File '$filename.cpp' created successfully in $(Get-Location)!" -ForegroundColor Green