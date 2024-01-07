from django.contrib import admin

# Register your models here.
from coper.models import ReactorModel, Task, TrunkType, DKnowledge, PKnowledge, CognitiveModel

@admin.register(ReactorModel, Task, TrunkType, DKnowledge, PKnowledge, CognitiveModel)
class ReactorModelAdmin(admin.ModelAdmin):
    pass

class TaskAdmin(admin.ModelAdmin):
    pass

class TrunkTypeAdmin(admin.ModelAdmin):
    pass

class DKnowledgeAdmin(admin.ModelAdmin):
    pass

class PKnowledgeAdmin(admin.ModelAdmin):
    pass

class CognitiveModelAdmin(admin.ModelAdmin):
    pass