param(
    [Parameter(Mandatory=$true, HelpMessage="Nhap 'backup' de sao luu hoac 'restore' de khoi phuc")]
    [ValidateSet("backup", "restore")]
    [string]$Action,
    
    [string]$BackupDir = ".\sublime_sync_backup"
)

$sublimePackagesPath = "$env:APPDATA\Sublime Text\Packages"
$projectClangdPath = "$env:USERPROFILE\Documents\cpp-training\.clangd"

# Dam bao duong dan luu tru tuyet doi
$BackupDir = Resolve-Path $BackupDir -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Path
if (-not $BackupDir) { $BackupDir = Join-Path (Get-Location) "sublime_sync_backup" }

if ($Action -eq "backup") {
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host " BAT DAU SAO LUU 100% CAU HINH (LOC THEME) " -ForegroundColor Green
    Write-Host "==========================================" -ForegroundColor Cyan
    
    if (-not (Test-Path $BackupDir)) { New-Item -ItemType Directory -Path $BackupDir | Out-Null }
    
    # 1. Quet va sao luu toan bo thu muc Packages (Bao gom User, LSP, SublimeLinter, v.v.)
    Write-Host "[Dang quet] Bat dau sao luu thu muc Packages..."
    $destPackagesPath = Join-Path $BackupDir "Packages"
    
    # Loc bo cac file giao dien thuan tuy: .sublime-theme, .sublime-color-scheme, .tmTheme
    $filesToBackup = Get-ChildItem -Path $sublimePackagesPath -Recurse -File | Where-Object {
        $_.Extension -notmatch "\.(sublime-theme|sublime-color-scheme|tmTheme)$"
    }
    
    $count = 0
    foreach ($file in $filesToBackup) {
        # Tinh toan duong dan tuong doi de tai tao dung cau truc
        $relativePath = $file.FullName.Substring($sublimePackagesPath.Length + 1)
        $destFile = Join-Path $destPackagesPath $relativePath
        $destDir = Split-Path $destFile
        
        if (-not (Test-Path $destDir)) { New-Item -ItemType Directory -Path $destDir | Out-Null }
        Copy-Item -Path $file.FullName -Destination $destFile -Force
        $count++
    }
    Write-Host "[OK] Da sao luu $count tep cau hinh/plugins tu thu muc Packages (Da loai tru giao dien)." -ForegroundColor Yellow
    
    # 2. Sao luu file du an .clangd
    if (Test-Path $projectClangdPath) {
        Copy-Item -Path $projectClangdPath -Destination (Join-Path $BackupDir ".clangd") -Force
        Write-Host "[OK] Da sao luu cau hinh du an: .clangd" -ForegroundColor Yellow
    }
    
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host " HOAN TAT SAO LUU TAI: $BackupDir" -ForegroundColor Green
}
elseif ($Action -eq "restore") {
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host " BAT DAU KHOI PHUC CHINH XAC 100% CAU TRUC " -ForegroundColor Green
    Write-Host "==========================================" -ForegroundColor Cyan
    
    if (-not (Test-Path $BackupDir)) {
        Write-Error "Khong tim thay du lieu sao luu tai: $BackupDir"
        exit
    }
    
    # 1. Khoi phuc toan bo thu muc Packages
    $srcPackagesPath = Join-Path $BackupDir "Packages"
    if (Test-Path $srcPackagesPath) {
        if (-not (Test-Path $sublimePackagesPath)) { New-Item -ItemType Directory -Path $sublimePackagesPath -Force | Out-Null }
        
        # Sao chep va ghi de tai tao 100% cau truc thu muc
        Copy-Item -Recurse -Force -Path "$srcPackagesPath\*" -Destination $sublimePackagesPath
        Write-Host "[OK] Da khoi phuc toan bo thu muc Packages (User, LSP, Linter...)." -ForegroundColor Yellow
    }
    
    # 2. Khoi phuc file cau hinh cap du an
    $srcClangd = Join-Path $BackupDir ".clangd"
    if (Test-Path $srcClangd) {
        $projectDir = Split-Path $projectClangdPath
        if (-not (Test-Path $projectDir)) { New-Item -ItemType Directory -Path $projectDir -Force | Out-Null }
        Copy-Item -Force -Path $srcClangd -Destination $projectClangdPath
        Write-Host "[OK] Da khoi phuc file du an: .clangd" -ForegroundColor Yellow
    }
    
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host " HOAN TAT KHOI PHUC THANH CONG!" -ForegroundColor Green
    Write-Host " Hay khoi dong lai Sublime Text." -ForegroundColor White
}
