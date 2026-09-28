$files = Get-ChildItem -Path . -File -Recurse | Where-Object { $_.FullName -notmatch '\\.git\\' -and $_.Name -ne 'rename_script.ps1' }
foreach ($file in $files) {
    $content = [System.IO.File]::ReadAllText($file.FullName)
    if ($content -match '(?i)yadb') {
        $newContent = $content -creplace 'yadb', 'minidb' -creplace 'YADB', 'MiniDB' -creplace 'Yadb', 'MiniDB'
        [System.IO.File]::WriteAllText($file.FullName, $newContent, (New-Object System.Text.UTF8Encoding($false)))
    }
}

$items = Get-ChildItem -Path . -Recurse | Where-Object { $_.FullName -notmatch '\\.git\\' -and $_.Name -match '(?i)yadb' -and $_.Name -ne 'rename_script.ps1' } | Sort-Object -Property @{Expression={$_.FullName.Length}; Descending=$true}
foreach ($item in $items) {
    $newName = $item.Name -creplace 'yadb', 'minidb' -creplace 'YADB', 'MiniDB' -creplace 'Yadb', 'MiniDB'
    Rename-Item -Path $item.FullName -NewName $newName
}
